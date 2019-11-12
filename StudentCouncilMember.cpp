#include "StudentCouncilMember.h"

StudentCouncilMember::StudentCouncilMember(string name): StudentDefault(name)
{
}
int StudentCouncilMember::doTheRetakeExam()
{
	return 3 + rand() % 3;
}
StudentCouncilMember::~StudentCouncilMember()
{

}

