#include "Person.h"
#include <iostream>
#include <string>

Person::Person()
{
	this->firstName = "Unknown";
	this->lastName = "Name";
	this->age = 0;
}

Person::Person(std::string fName, std::string lName)
{
	this->firstName = fName;
	this->lastName = lName;
}

Person::Person(std::string fName, std::string lName, int age)
{
	this->firstName = fName;
	this->lastName = lName;

	this->age = age;
}

Person::~Person()
{
}

void Person::SayHello()
{
	std::cout << "Hello!" << std::endl;
}

void Person::display() const
{
	std::cout << this->firstName << " " << this->lastName << ", " << this->age << std::endl;
}

void Person::SetFirstName(std::string fname)
{
	this->firstName = fname;
}

std::string Person::GetFirstName()
{
	return this->firstName;
}

void Person::SetLastName(std::string lname)
{
	this->lastName = lname;
}

std::string Person::GetLastName()
{
	return this->lastName;
}

void Person::SetAge(int age)
{
	if (age > 0) {
		this->age = age;
	}
	else {
		std::cout << "Please enter a valid age!" << std::endl;
	}
}

int Person::GetAge()
{
	return this->age;
}

void Person::OutputAge()
{
	std::cout << "I am " << age << " years old." << std::endl;
}

void SomeExternalFunction(Person & person)
{
	std::cout << person.GetFirstName() << std::endl;
}
