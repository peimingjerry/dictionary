
#include "person.h"
#include "skipList.h"

#define MAX_KEY 1000000
int main( void ) { 

    SkipList<Person,long> list( MAX_KEY );
    SkipNode<Person,long> *p; 
    Person a, b, c, d, e;

    a = Person(1102, "A", 27);
    b = Person(1000, "B", 22);
    c = Person(1108, "C", 25);
    d = Person(1001, "D", 23);
    e = Person(999, "E", 20);

    // Insert
    list.Insert(1102, a); 
    list.Insert(1000, b); 
    list.Insert(1108, c); 
    list.Insert(1101, d); 
    list.Insert(999, e); 

    p = list.Begin();
    while ( p ) { 
        p->data.printPersonInfo();
        p = list.Next( p );
    }   

    // Remove
    list.Remove(1000, b); 
    cout<<"\nAfter delete B:"<<endl;
    p = list.Begin();
    while ( p ) { 
        p->data.printPersonInfo();
        p = list.Next( p );
    }   

    // Search
    cout<<"\nNow searching A:"<<endl;
    p = list.Search(1102);
    if ( p ) 
        p->data.printPersonInfo();
    cout<<"Now searching B:"<<endl;
    p = list.Search(1000);
    if ( p ) 
        p->data.printPersonInfo();
    else
        cout<<"Cannot find person with ID:1000!"<<endl;
    cout<<"Now searching C:"<<endl;
    p = list.Search(1108);
    if ( p ) 
        p->data.printPersonInfo();
    return 0;
}
