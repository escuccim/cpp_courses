// PointersLab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Person.h"
#include "math.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include "Handle.h"
#include "SavingsAccount.h"
#include <fstream>
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

void openCloseFilesExplicitly()
{
	// Declare file stream objects (files aren't opened yet).
	std::ofstream ofile;
	std::ifstream ifile;
	std::fstream  iofile;

	// Open the files.
	ofile.open("file1.dat");    // Opens file1.dat for writing.
	ifile.open("file2.dat");    // Opens file2.dat for reading.
	iofile.open("file3.dat");   // Opens file3.dat for reading/writing.

	// Use the files...

	// Close the files.
	ofile.close();
	ifile.close();
	iofile.close();
}

void openCloseFilesImplicitly()
{
	// Declare file stream objects (files opened implicitly by constructors).
	std::ofstream ofile("file1.dat");
	std::ifstream ifile("file2.dat");
	std::fstream  iofile("file3.dat");
}



class tempStat
{
public:
	// Data members.
	double minimum, maximum;

	// Constructor.
	tempStat(double min = 0.0, double max = 0.0)
		: minimum(min), maximum(max)
	{}

	// Helper method, to write a tempStat object to a file in binary format.
	void write(std::ostream & os)
	{
		os.write((char*)&minimum, sizeof(double));
		os.write((char*)&maximum, sizeof(double));
	}

	// Helper method, to read a tempStat object from a file in binary format.
	void read(std::istream & is)
	{
		is.read((char*)&minimum, sizeof(double));
		is.read((char*)&maximum, sizeof(double));
	}

	// Plus other members, as appropriate.

};

std::istream& operator >> (std::istream& is, tempStat & ts)
{
	is >> ts.minimum >> ts.maximum;
	return is;
}

std::ostream& operator << (std::ostream & os, const tempStat & ts)
{
	os << ts.minimum << "," << ts.maximum << std::endl;
	return os;
}

int tempStats() {
	std::ofstream ofile("tempStats.bin", std::ios_base::binary);
	if (ofile.is_open())
	{
		tempStat(-2.5, 7.5).write(ofile);
		tempStat(0, 9.9).write(ofile);
		tempStat(2.5, 11.0).write(ofile);
		tempStat(5.5, 14.5).write(ofile);
		tempStat(7.0, 17.7).write(ofile);
		tempStat(10.5, 23.7).write(ofile);
		tempStat(11.7, 29.5).write(ofile);
		tempStat(7.6, 22.9).write(ofile);
		tempStat(7.2, 21.5).write(ofile);
		tempStat(2.0, 16.0).write(ofile);
		tempStat(-4.7, 12.5).write(ofile);
		tempStat(-1.9, 8.5).write(ofile);

		ofile.close();

		std::cout << "Finished writing binary data to tempStats.bin." << std::endl;
	}
	else
	{
		std::cerr << "Couldn't open tempStats.bin for writing." << std::endl;
	}

	std::ifstream ifile("tempStats.bin", std::ios_base::binary);
	if (ifile.is_open())
	{
		while (!ifile.eof())
		{
			tempStat ts;
			ts.read(ifile);

			if (ifile.gcount() == 0)
			{
				break;  // If no bytes read, we're done.
			}

			std::cout << "Read temperature stats: " << ts << std::endl;
		}
		ifile.close();

		std::cout << "Finished reading binary data from tempStats.bin." << std::endl;
	}
	else
	{
		std::cerr << "Couldn't open tempStats.bin for reading." << std::endl;
	}
	
	return 0;
}

int stringstreams() {
	std::ostringstream oss(std::ios_base::binary);

	tempStat(-2.5, 7.5).write(oss);
	tempStat(0, 9.9).write(oss);
	tempStat(2.5, 11.0).write(oss);
	tempStat(5.5, 14.5).write(oss);
	tempStat(7.0, 17.7).write(oss);
	tempStat(10.5, 23.7).write(oss);
	tempStat(11.7, 29.5).write(oss);
	tempStat(7.6, 22.9).write(oss);
	tempStat(7.2, 21.5).write(oss);
	tempStat(2.0, 16.0).write(oss);
	tempStat(-4.7, 12.5).write(oss);
	tempStat(-1.9, 8.5).write(oss);

	std::istringstream iss(oss.str(), std::ios_base::binary);

	while (!iss.eof()) {
		tempStat ts;
		ts.read(iss);

		if (iss.gcount() == 0) {
			break;
		}

		std::cout << "Read temperature stats: " << ts; 
	}

	return 0;
}

int main() {
	std::fstream iofile;
	int total;

	// open the file
	iofile.open("donation_total.txt", ios::in);

	// read the total
	if (iofile.is_open()) {
		iofile >> total;
	}

	std::cout << "Initial donations: " << total << std::endl;

	std::string donor_string;
	
	iofile.close();

	iofile.open("donation_total.txt", ios::out);

	// loop until user quits
	while (donor_string != "Q" && donor_string != "q") {
		// prompt for input
		std::cout << "Please enter a name and a donation (enter q to quit): ";

		// read input
		std::getline(std::cin, donor_string);

		// put the text into a string stream
		std::istringstream iss(donor_string);
		std::string name;
		std::string amount;
		int iamount;

		if (donor_string != "Q" && donor_string != "q") {
			try {
				iss >> name >> amount;;
				// convert the amount to an int
				iamount = stoi(amount);

				// add it to the total
				total += iamount;

				std::cout << "Current total: " << total << endl;

				iofile.seekp(0);
				iofile << total << endl;
			}
			catch (...) {
				std::cout << "An error has occurred. Please make sure you enter a first name followed by a space and a donation." << std::endl;
			}
			
		}
	}

	// close the file
	iofile.close();
	std::cout << "Closing file" << endl;

	return 0;
}