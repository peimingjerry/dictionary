
#include "person.h"
#include "hashTable.h"

#define TABLE_SIZE  12
#define DEVITOR     11
#define ARRAY_SIZE  8

int main( void ) { 
    HashTable<Person, long> table(DEVITOR, TABLE_SIZE);

    // Insert
    long keys[ARRAY_SIZE] = {37, 25, 14, 36, 49, 68, 57, 11};
    for (int i=0;i<ARRAY_SIZE;i++) {
        char str[2];
        str[0] = 'A'+i;
        str[1] = '\0';
        Person person(keys[i], str, i+20);
        table.Insert(keys[i], person);
        person.printPersonInfo();
        table.Display();
        cout<<endl;
    }   

    // Search
    long search_keys[5] = {14, 11, 68, 36, 10};
    Person person;
    for (int i=0;i<5;i++) {
        cout<<"\nNow searching ID = "<<search_keys[i]<<":"<<endl;
        if (table.Search(search_keys[i], person)) {
            cout<<"Found!"<<endl;
            person.printPersonInfo();
        } else {
            cout<<"Cannot find person with ID = "<<search_keys[i]<<"!"<<endl;
        }   
    }   

    return 0;
}
