#pragma once
#include "StudentDefault.h"
class StudentCouncilMember: public StudentDefault
{
public:
	StudentCouncilMember(string name);

	int doTheRetakeExam() override;
	~StudentCouncilMember();
};

