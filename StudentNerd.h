#pragma once

#include "Student.h"

class StudentNerd: public Student
{
public:
    StudentNerd(const string &name);
    StudentNerd(Student* student);
    int doTheExam() override;
    int doTheRetakeExam() override;
    ~StudentNerd();
};

