
#ifndef HASHTABLE_H
#define HASHTABLE_H

enum Status {
    Active,
    Empty,
    Deleted
};

template <typename E, typename K>
class HashTable {
public:
    HashTable(int d, int size);

    ~HashTable() { delete[] ht; delete[] status; }

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
    E *ht;
    Status *status;
};

template <typename E, typename K>
HashTable<E,K>::HashTable(int d, int size) {
    divitor =d;
    tableSize = size;
    ht = new E[tableSize];
    status = new Status[tableSize];
    for (int i=0;i<tableSize;i++)
        status[i] = Empty;
}

template <typename E, typename K>
bool HashTable<E,K>::Insert(const K k1, const E &e1) {
    int pos = GetPos(k1);
    if (status[pos] != Active) {
        ht[pos] = e1; 
        status[pos] = Active;
        return true;
    }   
    if (status[pos]==Active && ht[pos]==k1) {
        cout<<"Cannot insert this element since it is already there!"<<endl;
        return false;
    }
    cout<<"Table full and cannot insert!"<<endl;
    return false;
}

template <typename E, typename K>
bool HashTable<E,K>::Search(const K k1, E &e1) {
    int pos = GetPos(k1);
    if (status[pos]!=Active || ht[pos]!=k1)
        return false;
    e1 = ht[pos];
    return true;
}

template <typename E, typename K>
int HashTable<E,K>::GetPos(K k1) {
    int i = k1 % divitor;
    int j = i;
    do {
        if (status[j]==Empty || status[j]==Active && ht[j]==k1) {
            return j;
        } else {
            j = ( j + 1 ) % divitor;
        }
    } while (j != i);

    return j;
}

template <typename E, typename K>
void HashTable<E,K>::Display() {
    cout<<"\t";
    for (int i=0;i<tableSize;i++) {
        cout<<i<<"\t";
    }
    cout<<endl<<"\t";
    for (int i=0;i<tableSize;i++) {
        if (status[i]==Active)
            cout<<ht[i].getKey()<<"\t";
        else
            cout<<"NULL\t";
    }
    cout<<""<<endl;
}

#endif
