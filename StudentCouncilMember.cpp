#include "StudentCouncilMember.h"

StudentCouncilMember::StudentCouncilMember(const string &name): StudentDefault(name)
{
}
StudentCouncilMember::StudentCouncilMember(Student* student) : StudentDefault(student->getName())
{
}
int StudentCouncilMember::doTheRetakeExam()
{
	return 3 + rand() % 3;
}
StudentCouncilMember::~StudentCouncilMember()
{
}

