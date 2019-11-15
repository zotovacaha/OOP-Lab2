#include "StudentNerd.h"

StudentNerd::StudentNerd(string name): Student(name, (4 + rand() % 2))
{
	
}
int StudentNerd::doTheExam()
{
    return 4 + rand() % 2;
}
int StudentNerd::doTheRetakeExam()
{
    return 4 + rand() % 2;
}
StudentNerd::~StudentNerd()
{
	
}
