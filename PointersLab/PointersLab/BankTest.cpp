// PointersLab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
#include "Person.h"
#include "math.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Handle.h"
#include "SavingsAccount.h"
using namespace std;

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

int StudentsAndPeople()
{
	Student student1("Eric", "S", 41, "Chemin des Fougeres 4", "Morgins", "1875", "794435410");
	Student student2("Lisa", "S", 41, "Chemin des Fougeres 4", "Morgins", "1875", "794435410");
	Student student3("Dan", "S", 41, "Chemin des Fougeres 4", "Morgins", "1875", "794435410");

	std::cout << "Student 1: " << student1.GetFirstName() << " " << student1.GetLastName() << std::endl;
	student1.display();

	Course course("Intermediate C++");

	std::cout << course.name << endl;

	course.addStudents(student1, student2, student3);
	/*course->addStudent(*student2);
	course->addStudent(*student3);*/

	Teacher *teacher = new Teacher("David", "S", 41, "Chemin des Fougeres 4", "Morgins", "1875", "794435410");

	std::cout << "Teacher: " << teacher->GetFirstName() << std::endl;

	course.addTeacher(*teacher);

	teacher->GradeStudent();

	Handle h;
	h.someOperationOnBody();

	Person *p = new Student("Test", "Student", 25);
	p->display();

	return 0;
}

void FreezeMe(Freezable & f) {
	f.freeze();
}

int bankAccounts() {
	SavingsAccount account(10000, 2.5);

	std::cout << account.getTermsAndConditions() << std::endl;
	std::cout << account.getGuaranteedLimit() << std::endl;

	account.deposit(100);
	account.deposit(200);
	account.withdraw(50);
	account.earnInterest();

	FreezeMe(account);

	account.deposit(1000);
	account.deposit(2000);
	account.withdraw(500);
	account.earnInterest();

	account.unfreeze();

	account.deposit(10000);
	account.earnInterest();

	return 0;
}

int main() {
	Student student("Eric", "S", 41);

	std::cout << "[" << student.GetAge() << "]" << std::endl;
	std::cout << "[" << std::left << std::setw(10) << student.GetAge() << "]" << std::endl;
	std::cout << "[" << std::right << std::setw(10) << student.GetAge() << "]" << std::endl;
	std::cout << "[" << std::internal << std::setw(10) << -student.GetAge() << "]" << std::endl;
}