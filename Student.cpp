#include "Student.h"

Student::Student(const string &name, int minGrade)
{
    this->name = name;
	this->minGrade = minGrade;
}
Student::Student()
{
    this->name = "";
    this->minGrade = 0;
}
void Student::addGroupNumber(int groupNumber)
{
    groupNumbers.push_back(groupNumber);
}
void Student::deleteGroupNumber(int groupNumber)
{
    vector<int>::iterator position = find(groupNumbers.begin(), groupNumbers.end(), groupNumber);
    if (position != groupNumbers.end())
    {
        groupNumbers.erase(position);
    }
}

//GETTERS
const string& Student::getName()
{
    return this->name;
}
int Student::getMinGrade()
{
    return this->minGrade;
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
void Student::setName(const string &name)
{
    this->name = name;
}



