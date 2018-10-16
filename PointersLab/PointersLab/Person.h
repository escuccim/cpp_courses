#pragma once

#include <string>

class Person {
private:
	std::string firstName;
	std::string lastName;
	int age;

protected:
	std::string phone;

public:
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

	virtual void OutputIdentity() = 0;
	virtual void OutputAge();

	friend void SomeExternalFunction(Person &person);
};
