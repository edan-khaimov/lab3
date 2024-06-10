#ifndef PERSON_H
#define PERSON_H
#include "MyString.h"

typedef MyString PersonID;

class Person
{
private:
    PersonID id;
    MyString firstName;
    MyString middleName;
    MyString lastName;

public:
    Person()
    {
        id = "";
        firstName = "";
        middleName = "";
        lastName = "";
    }

    Person(PersonID id, MyString firstName, MyString middleName, MyString lastName)
    {
        this->id = id;
        this->firstName = firstName;
        this->middleName = middleName;
        this->lastName = lastName;
    }

    Person(const Person &person)
    {
        this->id = person.id;
        this->firstName = person.firstName;
        this->middleName = person.middleName;
        this->lastName = person.lastName;
    }

    MyString GetId()
    {
        return this->id;
    }

    MyString GetFirstName()
    {
        return this->firstName;
    }

    MyString GetMiddleName()
    {
        return this->middleName;
    }

    MyString GetLastName()
    {
        return this->lastName;
    }

    friend std::istream &operator>>(std::istream &in, Person &person)
    {
        std::cout << "Enter first name: " << std::endl;
        in >> person.firstName;
        std::cout << "Enter middle name: " << std::endl;
        in >> person.middleName;
        std::cout << "Enter last name: " << std::endl;
        in >> person.lastName;
        std::cout << "Enter id: " << std:: endl;
        in >> person.id;
        return in;
    }

    friend std::ostream &operator<<(std::ostream &out, const Person &person)
    {
        return out << "Person with " << person.id << " id: " << person.firstName << " " << person.middleName << " " << person.lastName << std::endl;
    }

    bool operator==(Person man)
    {
        return ((id == man.GetId()) && (middleName == man.GetMiddleName()) && (firstName == man.GetFirstName()) &&
            (lastName == man.GetLastName()));
    }
};

#endif