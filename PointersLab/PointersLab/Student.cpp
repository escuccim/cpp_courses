#include "Student.h"
#include <iostream>
#include "Person.h"

Student::Student()
{
}

Student::Student(std::string fname, std::string lname, int age) : Person(fname, lname, age)
{

}

Student::Student(std::string fname, std::string lname, int age, std::string address, std::string city, std::string postcode, std::string phone) : Person(fname, lname, age)
{
	/*this->firstName = fname;
	this->lastName = lname;
	this->age = age;*/
	this->address = address;
	this->city = city;
	this->postalCode = postcode;
	this->phoneNumber = phone;
}


Student::~Student()
{
}

std::string Student::getAddress()
{
	return std::string();
}

std::string Student::getCity()
{
	return std::string();
}

std::string Student::getPostalCode()
{
	return std::string();
}

std::string Student::getPhoneNumber()
{
	return std::string();
}

void Student::display()
{
	Person::display();
	std::cout << "This is a student" << std::endl;
}

void Student::SitInClass()
{
	std::cout << "Sitting in main theater" << std::endl;
}
