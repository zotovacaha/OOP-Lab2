#pragma once

#include "Student.h"

class StudentDefault: public Student
{
public:
	StudentDefault(const string &name);
	StudentDefault(Student* student);
	int doTheExam() override;
	int doTheRetakeExam() override;
	
};

