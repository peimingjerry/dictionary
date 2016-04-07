
#ifndef SkipList_H
#define SkipList_H

#define MAX_LEVL 100

template <class E, class K>
struct SkipNode {
    E data;
    SkipNode<E,K> ** link;
    SkipNode( int maxLevel = MAX_LEVL ) {
        link = new SkipNode<E,K> *[maxLevel+1];
        int i;
        for ( i=0;i<=maxLevel;i++ )
            link[i] = NULL;
    }
};

template <class E, class K>
class SkipList {
public:
    SkipList( K large, int maxLevel=MAX_LEVL );
    ~SkipList();
    SkipNode<E,K> * Search( const K k1 ) const;
    void Insert( const K k1, E& e1 );
    void Remove( const K k1, E& e1 );
    SkipNode<E,K> * Begin();
    SkipNode<E,K> * Next( SkipNode<E,K> * current );
    E& GetData( SkipNode<E,K> * current );
private:
    SkipNode<E,K> * head;
    SkipNode<E,K> * tail;
    SkipNode<E,K> ** last;
    int maxLevel;
    int level;
    int Level();    // Funtion to get random level for any inserted node
    K TailKey;      // Max value of Key, stored in tail node
    SkipNode<E,K> * SaveSearch( const K k1 ) const;
};

template <class E, class K>
SkipList<E,K>::SkipList( K large, int maxLevel ) {
    int i;

    this->maxLevel = maxLevel;
    level = 0;
    head = new SkipNode<E,K>(maxLevel+1);
    tail = new SkipNode<E,K>(0);
    last = new SkipNode<E,K> *[maxLevel+1];
    TailKey = large;
    tail->data = TailKey;
    for ( i=0;i<=maxLevel;i++ )
        head->link[i] = tail;   // initially, tail node should be linked in
}

template <class E, class K>
SkipList<E,K>::~SkipList() {
}

template <class E, class K>
SkipNode<E,K> * SkipList<E,K>::Search( const K k1 ) const {
    SkipNode<E,K> * p = head;
    int i;
    
    for ( i=level;i>=0;i-- ) {
        while ( p->link[i]->data < k1 ) {
            p = p->link[i];
        }   
    }   
    if ( p->link[0]->data == k1 )
        return p->link[0];
    else
        return NULL;
}       

template <class E, class K>
SkipNode<E,K> * SkipList<E,K>::SaveSearch( const K k1 ) const {
    SkipNode<E,K> * p = head;
    int i;
    
    for ( i=level;i>=0;i-- ) {
        while ( p->link[i]->data < k1 ) {
            p = p->link[i];
        }   
        last[i] = p;
    }   
    
    return p->link[0];
}   

template <class E, class K>
int SkipList<E,K>::Level() {
    int lev = 0;
    while ( rand() <= RAND_MAX/2 )
        lev++;
    return (lev<maxLevel)?lev:maxLevel;
}   

template <class E, class K>
void SkipList<E,K>::Insert( const K k1, E& e1 ) {
    SkipNode<E,K> *p, *pNew;
    int newLevel, i;

    p = SaveSearch( k1 );
    if ( p && p->data == k1 ) {
        p->data = e1;
    } else {
        newLevel = Level();
        if ( newLevel > level ) {
            newLevel = ++level;     // update level
            last[newLevel] = head;  // ?
        }
        pNew = new SkipNode<E,K>( newLevel + 1 );
        pNew->data = e1;
        for ( i=0;i<=newLevel;i++) {
            pNew->link[i] = last[i]->link[i];
            last[i]->link[i] = pNew;
        }
    }
}

template <class E, class K>
void SkipList<E,K>::Remove( const K k1, E& e1 ) {
    SkipNode<E,K> *p;
    int i;

    p = SaveSearch( k1 );
    if ( p && p->data == k1 ) {
        for ( i=0;i<=level && last[i]->link[i]==p;i++)
            last[i]->link[i] = p->link[i];
        while ( level>0 && head->link[level]==tail )
            level--;        // modify total level after delete
        e1 = p->data;
        delete p;
    }
}

template <class E, class K>
SkipNode<E,K> * SkipList<E,K>::Begin() {
    return head->link[0];
}

template <class E, class K>
SkipNode<E,K> * SkipList<E,K>::Next( SkipNode<E,K> * current ) {
    SkipNode<E,K> * p = current->link[0];
    return ( p->data < TailKey )?p:NULL;
}

template <class E, class K>
E& SkipList<E,K>::GetData( SkipNode<E,K> * current ) {
    return current->data;
}

#endif
