#pragma once
#include <string>
#include "Person.h"

class Student : public Person
{
private:
	/*std::string firstName;
	std::string lastName;
	int age;*/
	std::string address;
	std::string city;
	std::string postalCode;
	std::string phoneNumber;

public:
	Student();
	Student(std::string fname, std::string lname, int age);
	Student(std::string fname, std::string lname, int age, std::string address, std::string city, std::string postcode, std::string phone);
	virtual ~Student();
	
	std::string getAddress();
	std::string getCity();
	std::string getPostalCode();
	std::string getPhoneNumber();

	virtual void display();
	void SitInClass();
};

