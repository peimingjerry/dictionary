
#ifndef Person_H
#define Person_H

#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

#define DefaultID 0
#define DefaultAge 0

class Person
{
public:
    Person() {
        ID = DefaultID;
        name = ""; 
        age = DefaultAge;
    }   
    Person( long ID, string name, int age ) { 
        this->ID = ID; 
        this->age = age;
        this->name = name;
    }   
    ~Person() {
    }   
    Person& operator = ( long k1 ) { 
        ID = k1; 
        return *this;
    }   
    bool operator == ( long k1 ) { 
        return ( ID == k1 )?true:false;
    }   
    bool operator != ( long k1 ) { 
        return ( ID != k1 )?true:false;
    }   
    bool operator < ( long k1 ) { 
        return ( ID < k1 )?true:false;
    }   
    bool operator > ( long k1 ) { 
        return ( ID > k1 )?true:false;
    }   
    bool operator == ( Person &pr ) { 
        return ( ID == pr.ID )?true:false;
    }   
    bool operator < ( Person &pr ) { 
        return ( ID < pr.ID )?true:false;
    }   
    bool operator > ( Person &pr ) { 
        return ( ID > pr.ID )?true:false;
    }   
    void printPersonInfo() {
        cout<<"ID: "<<ID<<"    Name: "<<name<<"    Age: "<<age<<endl;
    } 
    long getKey() {
        return ID; 
    }

private:
    long ID;
    string name;
    int age;
};

#endif
