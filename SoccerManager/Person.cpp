#include "Person.h"

// constructor
Person::Person(string n,int a):
    name(n),
    age(a) {}
// get set functions
void Person::setName(string newName)
{
    name=newName;
}
string Person::getName()
{
    return name;
}
void Person::setAge(int newAge){
    age=newAge;
}
int Person::getAge(){
    return age;
}
