#include <iostream>
#include <string.h>
#include <math.h>
#include <string>

using namespace std;

class grade
{
private:
    char coursename[40];
    int mark;

public:
    void set_course_name(char *name)
    {
        strcpy(this->coursename, name);
    }
    void set_mark(int mark)
    {
        this->mark = mark;
    }

    char *get_course_name()
    {
        return this->coursename;
    }

    int get_mark()
    {
        return this->mark;
    }
};

class student
{
private:
    int studentID;
    char *name;
    grade *GradeList;

public:
    student(){
        this->studentID = 0;
        name = new char[40];
        this->GradeList = NULL;
    }
    void get_num_grades(int num){
        char course_name[40];
        int temp_mark;\
        GradeList = new grade[num];
        for(int i = 0; i < num; i++){
            cout << "Name of grade" << i + 1 << ": ";
            cin.ignore(INT32_MAX, '\0');
            cin.getline(course_name, 40);
            GradeList[i].set_course_name(this->name);
            cout << "Mark of grade" << i+1 <<": ";
            cin.ignore(INT32_MAX,'\0');
            cin >> temp_mark;
            GradeList[i].set_mark(temp_mark);
        }
    }
    void setID(int ID){
        this->studentID = ID;
    }
    
    void set_name(char* name){
        strcpy(this->name, name);
    }

    int get_ID(){
        return this->studentID;
    }

    char* get_name(){
        return this->name;
    }

    grade* get_GradeList(){
        return GradeList;
    }

    float avg(int length){
        float sum = 0;
        for(int i = 0; i < length; i++){
            cout << "Grade is: "<< GradeList[i].get_mark() <<  endl;
            sum += GradeList[i].get_mark();
        }
        return sum/length;
    }
};

int main(){
    int number_student, i;
    int student_id;
    char name_of_grade[40];
    int mark;
    char *name = new char[40];
    cout << "Enter number of Student? ";
    cin >> number_student;
    int number_of_grade;
    student list_student[number_student];
    for(i = 0; i < number_student; i++){
        cout << "--------------\n";
        cout << "Input details for student " << i + 1 << endl;
        cout << "Student ID? ";
        cin >> student_id;
        list_student[i].setID(student_id);
        fflush(stdin);
        cout << "Name? ";
        cin.ignore(INT32_MAX, '\0');
        cin.getline(name, 40);
        list_student[i].set_name(name);
        cout << "-------------\n";
        cout << "How many Grades? "; 
        cin >> number_of_grade;
        list_student[i].get_num_grades(number_of_grade);
        fflush(stdin);
    }

    int selection;
    cout << "Which student average grade? ";
    cin >> selection;
    cout << "Average is: " << list_student[selection-1].avg(number_of_grade);

    return 0;
}