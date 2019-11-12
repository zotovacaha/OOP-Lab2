#include "StudentDefault.h"

StudentDefault::StudentDefault(string name): Student(name,(2 + rand() % 4))
{
	
}
int StudentDefault::doTheExam()
{
	return 2 + rand() % 4;
}

int StudentDefault::doTheRetakeExam()
{
	return 2 + rand() % 4;
}

