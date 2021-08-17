#include <iostream>
#include <string.h>
#include <math.h>
#include <string>
#define max 10 // The maximum amount of student the list can contain

using namespace std;
class grade
{
private:
	char nameOfCourse[40];
	int mark;

public:
	void setName_of_course(char *name)
	{
		strcpy(nameOfCourse, name);
	}
	void set_mark(int mark)
	{
		this->mark = mark;
	}
	char *getName_of_course()
	{
		return nameOfCourse;
	}

	int get_mark()
	{
		return mark;
	}
};

class Student
{
private:
	int studentID;
	char *name;
	grade *GradeList;

public:
	Student()
	{
		studentID = 0;
		name = new char[40];
		GradeList = NULL;
	}

	void getNumberOfGrades(int number)
	{
		char CourseName[40];
		string mark;
		GradeList = new grade[number];
		for (int i = 0; i < number; i++)
		{
			cout << "Name of grade" << i + 1 << ": ";
			cin.getline(CourseName, 40);
			GradeList[i].setName_of_course(name);
			fflush(stdin);
			cout << "Mark of grade" << i + 1 << ": ";
			cin >> mark;
			GradeList[i].set_mark(stoi(mark));
			fflush(stdin);
		}
	}
	void setID(int id)
	{
		studentID = id;
	}

	void setname(char *name)
	{
		strcpy(this->name, name);
	}

	int getID()
	{
		return studentID;
	}

	char *getname()
	{
		return name;
	}

	grade *getList()
	{
		return GradeList;
	}

	float average(int length)
	{
		float sum = 0;
		for (int i = 0; i < length; i++)
		{
			cout << "grade is : " << GradeList[i].get_mark() << endl;
			sum += GradeList[i].get_mark();
		}

		return sum / length;
	}
};

int main()
{
	int number, i;
	string id;
	char nameOfGrade[40];
	string mark;
	char *name = new char[40];
	cout << "Enter number of Students? ";
	cin >> number;
	string numberOfGrades[number];
	Student list[number];
	for (i = 0; i < number; i++)
	{
		cout << "---------------\n";
		cout << "Input details for Student " << i + 1 << " : \n";
		cout << "Student ID? ";
		cin >> id;
		list[i].setID(stoi(id));
		fflush(stdin);
		cout << "Name? ";
		cin.getline(name, 40);
		list[i].setname(name);
		cout << "---------------\n";
		cout << "How many Grades? ";
		cin >> numberOfGrades[i];
		fflush(stdin);
		list[i].getNumberOfGrades(stoi(numberOfGrades[i]));
		fflush(stdin);
	}

	int index;
	cout << "Which student average grade ? ";
	cin >> index;
	cout << "Average is : " << list[index - 1].average(stoi(numberOfGrades[index - 1]));
	// Student huycao;
	// huycao.setID(1952713);
	// huycao.setname((char*)("cao ba huy"));
	// cout<<"your ID : "<<huycao.getID()<<endl<<"Name : "<<huycao.getname();
	// int n;
	// cout<<" \n How many grade : ";
	// cin>>n;
	// huycao.getNumberOfGrades(n);
	// huycao.getList()[0].set_mark(123);
	// huycao.getList()[0].setName_of_course((char*)"cao ba huy");
	// cout<<"mark : "<<huycao.getList()[0].get_mark()<<endl;
	// cout<<"name : "<<huycao.getList()[0].getName_of_course()<<endl;

	return 0;
}
