
#include "student.hpp"
class StudentNerd: public Student
{
public:
	StudentNerd(string name);
	int doTheExam() override;
	int doTheRetakeExam() override;
	~StudentNerd();
};

