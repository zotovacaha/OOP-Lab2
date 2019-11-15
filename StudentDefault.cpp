#include "StudentDefault.h"

StudentDefault::StudentDefault(const string &name): Student(name,(2 + rand() % 4))
{
	
}
StudentDefault::StudentDefault(Student* student) : Student(student->getName(), (2 + rand() % 4))
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
