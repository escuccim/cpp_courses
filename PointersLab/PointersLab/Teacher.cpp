#include "Teacher.h"
#include <iostream>
#include "Person.h"

Teacher::Teacher()
{
}

Teacher::Teacher(std::string fname, std::string lname, int age, std::string address, std::string city, std::string postcode, std::string phone) : Person(fname, lname, age)
{
	this->address = address;
	this->city = city;
	this->postalCode = postcode;
	this->phoneNumber = phone;
}


Teacher::~Teacher()
{
}


std::string Teacher::getAddress()
{
	return std::string();
}

std::string Teacher::getCity()
{
	return std::string();
}

std::string Teacher::getPostalCode()
{
	return std::string();
}

std::string Teacher::getPhoneNumber()
{
	return std::string();
}

void Teacher::GradeStudent()
{
	std::cout << "Student Graded" << std::endl;
}

void Teacher::SitInClass()
{
	std::cout << "Sitting at front of class" << std::endl;
}
