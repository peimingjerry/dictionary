
#ifndef HASHTABLE_H
#define HASHTABLE_H

enum Status {
    Active,
    Empty,
    Deleted
};

template <typename E>
struct HTNode {
    HTNode *pNext;
    E data;
    HTNode(const E & e1): data(e1), pNext(NULL) {}
};

template <typename E, typename K>
class HashTable {
public:
    typedef struct HTNode<E> Node;
    typedef Node * pointer;

    HashTable(int d, int size);

    ~HashTable();

    bool Search(const K k1, E &e1);

    bool Insert(const K k1, const E &e1);

    //void Remove(const K k1, E &e1);

    //void makeEmpty();

    void Display();

private:
    int GetPos(K k1);

private:
    int divitor;
    int tableSize;
    pointer * ht; 
};

template <typename E, typename K>
HashTable<E,K>::HashTable(int d, int size) {
    divitor = d;
    tableSize = size;
    ht = new pointer[tableSize];
    for (int i=0;i<tableSize;i++)
        ht[i] = NULL;
}

template <typename E, typename K>
HashTable<E,K>::~HashTable() { 
    for (int i=0;i<tableSize;i++) {
        while (ht[i] != NULL) {
            pointer cur = ht[i];
            ht[i] = cur->pNext;
            delete cur;
        }   
    }   
    delete[] ht;
}

template <typename E, typename K>
bool HashTable<E,K>::Insert(const K k1, const E &e1) {
    int pos = GetPos(k1);
    pointer cur = ht[pos];
    while (cur != NULL) {
        if (cur->data == k1) {
            cout<<"Cannot insert this element since it is already there!"<<endl;
            return false;
        }
        cur=cur->pNext;
    }
    pointer tmp = new Node(e1);
    tmp->pNext = ht[pos];
    ht[pos] = tmp;

    return true;
}

template <typename E, typename K>
bool HashTable<E,K>::Search(const K k1, E &e1) {
    int pos = GetPos(k1);
    pointer cur = ht[pos];
    while (cur != NULL) {
        if (cur->data == k1) {
            e1 = cur->data;
            return true;
        }
        cur = cur->pNext;
    }
    return false;
}

template <typename E, typename K>
int HashTable<E,K>::GetPos(K k1) {
    return (k1 % divitor);
}

template <typename E, typename K>
void HashTable<E,K>::Display() {
    for (int i=0;i<tableSize;i++) {
        cout<<i<<"\t";
        pointer cur = ht[i];
        while (cur != NULL) {
            cout<<cur->data.getKey()<<" -> ";
            cur = cur->pNext;
        }
        cout<<"^"<<endl;
    }
}

#endif
