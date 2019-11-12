
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <locale>
#include <ctime>
#include "student.h"
#include "studentDefault.h"
#include "StudentCouncilMember.h"
#include "StudentNerd.h"
#include "studentGroup.h"
#include "windows.h"

using namespace std;

int main(int argc, const char * argv[]) {
	setlocale(0, "");
    srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    Student* listOfAllStudents[10];
    StudentGroup* listOfAllGroups[5];
    string names[10] = {"Иванов Иван Иванович",
        "Смирнов Игорь Вадимович",
        "Кузнецов Семен Алексеевич",
        "Ахматова Анна Александровна",
        "Соловьева Елена Петровна",
        "Козлова Татьяна Станиславовна",
        "Васнецов Станислав Григорьевич",
        "Воробьев Григорий Вячеславович",
        "Архипова Инна Дмитриевна",
        "Журавлева Анастасия Викторовна"
    };

    int groups[5] = {111,222,333,444,555};
    for(int i=0; i<6; i++)
    {
		StudentDefault* student = new StudentDefault(names[i]);
        listOfAllStudents[i] = student;
    }
	for (int i = 6; i < 8; i++)
	{
		StudentNerd* student = new StudentNerd(names[i]);
		listOfAllStudents[i] = student;
	}
	for (int i = 8; i < 10; i++)
	{
		StudentCouncilMember* student = new StudentCouncilMember(names[i]);
		listOfAllStudents[i] = student;
	}

    for(int i=0; i<5; i++)
    {
        StudentGroup* studentGroup = new StudentGroup(groups[i]);
        listOfAllGroups[i] = studentGroup;
    }
    cout << "Список всех студентов: "<<endl;
    for(int i=0; i<10; i++)
    {
        cout<<i+1<<"."<<listOfAllStudents[i]->getName()<<endl;
    }
    for(int i=0; i<10;i++)
    {
        int indGroup = rand()%5;
        int indStud = rand()%10;
        listOfAllGroups[indGroup]->addStudent(listOfAllStudents[indStud]);
    }
    cout<<"Группы были заполнены студентами."<<endl;
    //Вывод в ostream
    filebuf fb;
    fb.open ("test.txt",ios::out);
    ostream os(&fb);
    for(int i = 0; i<5; i++)
    {
        //Отсортирован по возрастанию минимальной оценки
        vector<Student*> tempVector = listOfAllGroups[i]->getListOfStudentsSortedByGrades();
        if(tempVector.empty())
        {
            os<<"В группе "<<listOfAllGroups[i]->getGroupNumber()<<" нет студентов."<<endl;
        }
        else{
        os << "Студенты группы "<<listOfAllGroups[i]->getGroupNumber()<<":"<<endl;
        for(int i=0; i<tempVector.size(); i++)
        {
            os<<i+1<<"."<<tempVector[i]->getName()<<endl<<"Минимальная оценка: "<<tempVector[i]->getMinGrade()<<endl<<"Кол-во групп: ";
            os<<tempVector[i]->getGroupCount()<<endl<<"Группы: ";
            for(int j=0; j<tempVector[i]->getGroupCount(); j++)
            {
                os<<tempVector[i]->getGroupNumbers()[j]<<" ";
            }
            os<<endl;
        }
        }
    }
    fb.close();
    cout<<"Список студентов всех групп был выведен в файл."<<endl;
    cout<<"Список групп: ";
    for(int i=0; i<5; i++)
    {
      cout<<listOfAllGroups[i]->getGroupNumber()<<" ";
    }
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout<< "Проведение экзамена в группе " << listOfAllGroups[i]->getGroupNumber()<< endl;
		listOfAllGroups[i]->startExam();
	}
	Student* listOfAllNerdStudents[10];
	for (int i = 0; i < 10; i++)
	{
		listOfAllNerdStudents[i]=listOfAllStudents[i]->switchToNerd();
	}
	for (int i = 0; i < 5; i++)
	{
		listOfAllGroups[i]->deleteAllStudents();
	}
	for (int i = 0; i < 10; i++)
	{
		int indGroup = rand() % 5;
		int indStud = rand() % 10;
		listOfAllGroups[indGroup]->addStudent(listOfAllNerdStudents[indStud]);
	}
	cout << "Все студенты были переведены в ботаников. " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "Проведение экзамена в группе " << listOfAllGroups[i]->getGroupNumber() << endl;
		listOfAllGroups[i]->startExam();
	}
	system("pause");
	
return 0;
}


