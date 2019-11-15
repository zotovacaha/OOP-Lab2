#ifndef student_h
#define student_h

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class Student
{
private:
    string name;
    int minGrade;
    vector<int> groupNumbers;
public:
void addGroupNumber(int groupNumber);
    void deleteGroupNumber(int groupNumber);
    const string& getName();
    void setName(const string &name);
    virtual int doTheExam() = 0;
    virtual int doTheRetakeExam() = 0;
    int getGroupCount();
    int getMinGrade();
    const vector<int>& getGroupNumbers();
    Student(const string &name, int min_grade);
    Student();
    virtual ~Student() = default;
};
#endif 

