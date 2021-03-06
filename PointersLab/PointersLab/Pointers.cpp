// PointersLab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

class Person {
public:
	string name;
	int age;
	int height;
	int weight;
};

void ModifyPerson(Person &person) {
	person.name = "Lisa";
}

void PassByValue(int i) {
	cout << "PassByValue" << endl;
	i += 1;
	cout << "i is " << i << endl;
}

void PassByRef(int *i) {
	cout << "PassByValue, i is " << *i << endl;
	*i = 50;
	cout << "PassByValue, i is " << *i << endl;
}

int main()
{
	int num1;
	int *pNum = new int;

	num1 = 3;
	*pNum = 5;

	cout << "num1: " << num1 << endl;
	cout << "pNum: " << pNum<< endl;
	cout << "*pNum: " << *pNum << endl;

	PassByValue(num1);
	PassByValue(pNum);

	cout << "in main num1 is " << num1;

	PassByRef(&num1);
	cout << "in main num1 is " << num1;

	double *foo = new double;
	*foo = 17;

	cout << "foo: " << foo << endl;
	cout << "*foo: " << *foo << endl;

	delete foo;

	string bar = "Hello";
	cout << bar << endl;

	Person p;
	p.name = "Eric";
	p.age = 41;
	p.weight = 69;
	p.height = 79;

	cout << "Name: " << p.name << endl;
	ModifyPerson(p);
	cout << "New Name: " << p.name << endl;
}
