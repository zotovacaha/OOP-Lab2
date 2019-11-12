
#ifndef studentGroup_hpp

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "student.hpp"
#include "StudentDefault.h"

using namespace std;

class StudentGroup
{
private:
    int groupNumber;
    vector<Student*> listOfStudents;
public:
    void addStudent(Student* student);
    Student* getStudentByName(string &name);
    void deleteStudent(Student* student);
	void deleteAllStudents();
    int getGroupNumber();
    void setGroupNumber(int groupNumber);
	void startExam();
	void startRetakeExam(Student* student);
    vector<Student*> getListOfStudents();
    vector<Student*> getListOfStudentsSortedByGrades();
    StudentGroup(int number);
};
#endif 