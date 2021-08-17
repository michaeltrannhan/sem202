#include <iostream>
#include <string.h>
#include <string>
using namespace std;
class grade;
class Uni
{
private:
    int studentID;
    char name[40];
    int grade;
    grade *grad;
public:
    Uni()
    {
        this->studentID = 0;
        strcpy(this->name, "\0");
        this->grade = 0;
    }
    Uni(int studentid, char *name, int grade)
    {
        this->studentID = studentid;
        strcpy(this->name, name);
        this->grade = grade;
    }
};

class grade
{
private:
    char name_of_course[40];
    int mark;

public:
    grade()
    {
        strcpy(this->name_of_course, "\0");
        this->mark = 0;
    }
    grade(char *name, int mark)
    {
        strcpy(this->name_of_course, name);
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
    int mark;
    char namecourse[40];
    cout << "Enter the number of Students: ";
    cin >> numstudent;
    cout << "----------------------------------\n";

    int studentid, numgrade;
    char name[40];
    Uni *obj[numstudent];
    for (int i = 0; i < numstudent; i++)
    {
        cout << "Input details for Student " << i + 1 << "\n";
        cout << "Student ID? ";
        cin >> studentid;
        cout << "Name" << i + 1 << " : ";
        cin.ignore(INT16_MAX, '\n');
        cin.getline(name, 40);
        obj[i] = new Uni(studentid, name, numgrade);

        cout << "-------------------------------------\n";
        cout << endl;
        cout << "How many Grades? ";
        cin >> numgrade;
        cout << endl;
        grade *object[numgrade];
        for (int i = 0; i < numgrade; i++)
        {
            cout << "Name of grade " << i + 1 << " : ";
            cin.ignore(INT16_MAX, '\n');
            cin.getline(namecourse, 40);
            cout << endl;
            cout << "Mark of grade " << i + 1 << " : ";
            cin >> mark;
            cout << endl;
            object[i] = new grade(namecourse, mark);
        }
    }

    // cout << "How many Grades? ";
    // cin >> numgrade;
    // cout << endl;
    // grade *object[numgrade];
    // for (int i = 0; i < numgrade; i++)
    // {
    //     cout << "Name of grade " << i + 1 << " : ";
    //     cin.ignore(INT16_MAX, '\n');
    //     cin.getline(namecourse, 40);
    //     cout << endl;
    //     cout << "Mark of grade " << i + 1 << " : ";
    //     cin >> mark;
    //     cout << endl;
    //     object[i] = new grade(namecourse, mark);
    // }
    cout << "==========================";
    int selection;
    float avg;
    cout << endl;
    cout << "What student average grade? ";
    cin >> selection;
}