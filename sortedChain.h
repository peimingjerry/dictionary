
#ifndef SortedChain_H
#define SortedChain_H

#include <assert.h>
#include <iostream>
using std::cout;
using std::endl;
using std::cerr;

template <class E, class K>
struct ChainNode {
    E data;
    ChainNode<E,K> *link;
    ChainNode(): link( NULL ) {}; 
    ChainNode( E& e1, ChainNode<E,K> *next = NULL )
        : data( e1 ), link( next ) {}; 
};

template <class E, class K>
class SortedChain {
public:
    SortedChain() {
        first = new ChainNode<E,K>;
        assert( first );
    }   
    ~SortedChain() {
    }   
    ChainNode<E,K> *Search( const K k1 ) const;
    void Insert( const K k1, E& e1 );
    void Remove( const K k1, E& e1 );
    ChainNode<E,K> *Begin() {
        return first->link;
    }   
    ChainNode<E,K> *Next( ChainNode<E,K> *current ) const {
        if ( current )
            return current->link;
        else
            return NULL;
    }   

private:
    ChainNode<E,K> *first;
};

template <class E, class K>
ChainNode<E,K> *SortedChain<E,K>::Search( const K k1 ) const {
    ChainNode<E,K> *pChainNode = first->link;
    while ( pChainNode && pChainNode->data < k1 ) { 
        pChainNode = pChainNode->link;
    }   
    if ( pChainNode && pChainNode->data == k1 )
        return pChainNode;
    else
        return NULL;
}

template <class E, class K>
void SortedChain<E,K>::Insert( const K k1, E& e1 ) {
    ChainNode<E,K> * pChainNode = first->link;
    ChainNode<E,K> * pLast = first;

    while ( pChainNode && pChainNode->data < k1 ) {
        pLast = pChainNode;
        pChainNode = pChainNode->link;
    }
    if ( pChainNode && pChainNode->data == k1 ) {
        pChainNode->data = e1;
    } else {
        ChainNode<E,K> * pNew = new ChainNode<E,K>( e1 );
        if ( pNew == NULL ) {
            cerr << "Failed to allocate memory!"<<endl;
            exit(1);
        }
        pLast->link = pNew;
        pNew->link = pChainNode;
    }
}

template <class E, class K>
void SortedChain<E,K>::Remove( const K k1, E& e1 ) {
    ChainNode<E,K> * pChainNode = first->link;
    ChainNode<E,K> * pLast = first;
    while ( pChainNode && pChainNode->data < k1 ) {
        pLast = pChainNode;
        pChainNode = pChainNode->link;
    }
    if ( pChainNode && pChainNode->data == k1 ) {
        pLast->link = pChainNode->link;
        e1 = pChainNode->data;
        delete pChainNode;
    }
}

#endif
