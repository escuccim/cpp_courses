#pragma once

#include <string>

class Person {
private:

protected:
	std::string phone;

public:
	int age;
	std::string firstName;
	std::string lastName;


	Person();
	Person(std::string fName, std::string lName);
	Person(std::string fName, std::string lName, int age);

	virtual ~Person();

	void SayHello();

	void display() const;

	void SetFirstName(std::string fname);
	std::string GetFirstName();

	void SetLastName(std::string lname);
	std::string GetLastName();

	void SetAge(int age);
	int GetAge();

	virtual void OutputAge();

	friend void SomeExternalFunction(Person &person);
};
