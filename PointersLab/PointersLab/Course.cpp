#include "Course.h"



Course::Course()
{
	this->numStudents = 0;
}

Course::Course(std::string name)
{
	this->name = name;
}


Course::~Course()
{
}

void Course::addStudents(Student student1, Student student2, Student student3)
{
	this->students[0] = student1;
	this->students[1] = student2;
	this->students[2] = student3;

}

void Course::addTeacher(Teacher teacher)
{
	this->teacher = teacher;
}

void Course::setName(std::string name)
{
	this->name = name;
}
