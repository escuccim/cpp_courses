#pragma once
#include <string>
#include "Person.h"

class Teacher : public Person
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
	Teacher();
	Teacher(std::string fname, std::string lname, int age, std::string address, std::string city, std::string postcode, std::string phone);
	~Teacher();

	/*std::string getFirstName();
	std::string getLastName();
	int getAge();*/
	std::string getAddress();
	std::string getCity();
	std::string getPostalCode();
	std::string getPhoneNumber();

	void GradeStudent();
	void SitInClass();
};

