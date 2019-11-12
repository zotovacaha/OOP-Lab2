
#include "student.hpp"
#include "studentdefault.h"
#include "StudentCouncilMember.h"
#include "StudentNerd.h"

Student::Student(string name, int min_grade)
{
    this->name = name;
	this->min_grade = min_grade;
}
Student::Student()
{
  
    this->name = "";
    this->min_grade = 0;
}
void Student::addGroupNumber(int groupNumber)
{
    groupNumbers.push_back(groupNumber);
}
void Student::deleteGroupNumber(int groupNumber)
{
    vector<int>::iterator position = find(groupNumbers.begin(), groupNumbers.end(), groupNumber);
    if (position != groupNumbers.end()){
        groupNumbers.erase(position);
    }
}
StudentDefault* Student::switchToDefaultStudent()
{
	return new StudentDefault(this->name);
}
StudentNerd* Student::switchToNerd()
{
	return new StudentNerd(this->name);
}
StudentCouncilMember* Student::switchToCouncilMember()
{
	return new StudentCouncilMember(this->name);
}




//GETTERS
string Student::getName()
{
    return this->name;
}
int Student::getMinGrade()
{
    return this->min_grade;
}
int Student::getGroupCount()
{

	return this->groupNumbers.size();
}
const vector<int>& Student::getGroupNumbers()
{
    return this->groupNumbers;
}

//SETTERS
void Student::setName(string name)
{
    this->name = name;
}

