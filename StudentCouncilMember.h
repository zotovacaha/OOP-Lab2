#pragma once

#include "StudentDefault.h"

class StudentCouncilMember: public StudentDefault
{
public:
    StudentCouncilMember(const string &name);
    StudentCouncilMember(Student* student);
    int doTheRetakeExam() override;
    ~StudentCouncilMember();
};

