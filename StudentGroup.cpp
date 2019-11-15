#include "StudentGroup.h"

StudentGroup::StudentGroup(int number)
{
    this->groupNumber = number;
}
void StudentGroup::addStudent(Student* student)
{
    if(listOfStudents.size() < 20)
    {
    	if(find(listOfStudents.begin(), listOfStudents.end(), student) != listOfStudents.end()) 
	{
        cout<<"Данный студент уже находится в группе"<<endl;
        }
	else 
	{
            listOfStudents.push_back(student);
            student->addGroupNumber(this->groupNumber);
        }
    }
    else
    {
     	cout<<"В группе не может быть больше 20 студентов"<<endl;
    }
}
void StudentGroup::deleteStudent(Student* student)
{
    vector<Student*>::iterator position = find(listOfStudents.begin(), listOfStudents.end(), student);
    if (position != listOfStudents.end())
    {
        student->deleteGroupNumber(this->groupNumber);
        listOfStudents.erase(position);
    }
    else
    {
        cout<<"Студент не найден"<<endl;
    }
}
void StudentGroup::deleteAllStudents()
{
    for (auto& i : listOfStudents)
    {
        i->deleteGroupNumber(this->groupNumber);
    }
    listOfStudents.clear();
}
void StudentGroup::startExam()
{
    for (auto& i : listOfStudents)
    {
	int mark = i->doTheExam();
	if (mark == 2)
	{
	    cout << "Студент " << i->getName() << " завалил экзамен и отправлен на пересдачу" << endl;;
	    startRetakeExam(i);
	}
	else
	{
	    cout << "Студент " << i->getName() << " получил оценку " << mark << endl;
	}
    }
}
void StudentGroup::startRetakeExam(Student* student)
{
    int mark = student->doTheRetakeExam();
    string name = student->getName();
    if (mark == 2)
    {
	cout <<"Студент "<<student->getName()<<" завалил пересдачу." << endl;
	deleteStudent(student);
    }
    else 
    {
	cout << "Студент " <<student->getName()<< " получил оценку  " <<mark<< endl;
    }
}
//GETTERS
int StudentGroup::getGroupNumber()
{
    return this->groupNumber;
}
void StudentGroup::setGroupNumber(int groupNumber)
{
    this->groupNumber = groupNumber;
}
Student* StudentGroup::getStudentByName(string& name)
{
    int i = 0;
    for(i = 0; listOfStudents.size(); i++)
    {
        if (listOfStudents[i]->getName() == name)
	{
           return listOfStudents[i];
        }
    }
    return nullptr;
}
vector<Student*> StudentGroup::getListOfStudents()
{
    return listOfStudents;
}
vector<Student*> StudentGroup::getListOfStudentsSortedByGrades()
{
    vector<Student*> tempVector = listOfStudents;
    //SORT
    if (listOfStudents.empty())
    {
        cout << "В группе " << this->groupNumber << "нет студентов." << endl;
	return tempVector;
    }
    else 
    {
         sort(tempVector.begin(), tempVector.end(), [](Student* a, Student* b)
	 {
	     return a->getMinGrade() > b->getMinGrade();
	 });
    }
    return tempVector;
}




