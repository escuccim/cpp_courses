#pragma once
#include <string>
#include "Teacher.h"
#include "Student.h"

class Course
{
public:
	Course();
	Course(std::string name);
	~Course();

	Teacher teacher;
	Student students[3];
	int numStudents;
	std::string name;

	void addStudents(Student, Student, Student);
	void addTeacher(Teacher teacher);
	void setName(std::string name);
};

