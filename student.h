
#ifndef student_h
#define student_h

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;
class StudentDefault;
class StudentNerd;
class StudentCouncilMember;

class Student
{
private:
    string name;
    int min_grade;
    vector<int> groupNumbers;
public:
    void addGroupNumber(int groupNumber);
    void deleteGroupNumber(int groupNumber);
    string getName();
    void setName(string name);
	virtual int doTheExam() = 0;
	virtual int doTheRetakeExam() = 0;
	StudentDefault* switchToDefaultStudent();
	StudentNerd* switchToNerd();
	StudentCouncilMember* switchToCouncilMember();
    int getGroupCount();
    int getMinGrade();
    const vector<int>& getGroupNumbers();
    Student(string name, int min_grade);
    Student();
};
#endif 
