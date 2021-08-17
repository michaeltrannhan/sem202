#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Uni
{
private:
    int studentID;
    char name[40];
    int grade;

public:
    Uni()
    {
        this->studentID = 0;
        this->name = "\0";
        this->grade = 0;
    }
    Uni(int studentid, char *name, int grade)
    {
        this->studentID = studentid;
        this->name = name;
        this->grade = grade;
    }
};

class grade
{
private:
    char name_of_course[];
    int mark;

public:
    grade()
    {
        strcpy(this->name_of_course, "\0");
        this->mark = 0;
    }
    grade(char *name, int mark)
    {
        this->name_of_course = name;
        this->mark = mark;
    }
    int getgrade()
    {
        return this->mark;
    }
};

int main()
{
    int numstudent;
    cout << "Enter the number of Students: ";
    cin >> numstudent;
    cout << "\n ----------------------------------";

    int studentid, numgrade;
    char name[40];
    Uni *obj[numstudent];
    for (int i = 0; i < numstudent; i++)
    {
        cout << "Input details for Student " << i + 1 << " : \n";
        cout << "Student ID? ";
        cin >> studentid;
        cout << endl;
        bool over1= false;
        while(!over1){
            cout << "Name of grade " << i + 1 << " : ";
            cin.getline(name, sizeof(name));
            if(sizeof(name) > 40 || sizeof(name) < 0){
                cout << "Invalid length of name!\n ";
                over = true;
            }
        }
        obj[i] = new Uni(studentid, name, numgrade);
    }
    cout << "\n-------------------------------------";

    int mark;
    char namecourse[40];
    cout << "How many Grades? ";
    cin >> numgrade;
    cout << endl;
    grade *object[numgrade];
    for (int i = 0; i < numgrade; i++)
    {
        bool over= false;
        while(!over){
            cout << "Name of grade " << i + 1 << " : ";
            cin.getline(namecourse, sizeof(namecourse));
            if(sizeof(namecourse) > 40 || sizeof(namecourse) < 0){
                cout << "Invalid length of name!\n ";
                over = true;
            }
        }
        cout << endl;
        cout << "Mark of grade " << i + 1 << " : ";
        cin  >> mark;
        cout << endl;

        object[i] = new grade(namecourse, mark);
    }
}