#include <iostream>
#include <string.h>
#include <math.h>
#include <string>

#define max 10// max students

using namespace std;
class People{
    protected:
    char name[40];
    int id;
    public:
    People(){
        strcpy(this->name, "\0");
        this->id = 0;
    }
    void setName(char *name){
        strcpy(this->name, name);
    }
    void set_ID(int ID){
        this->id = ID;
    }
    char *getName(){
        return this->name;
    }
    int get_ID(){
        return this->id;
    }
};
class Ticket{
    protected:
    char flight_name[40];
    int value;
    public:
    void set_flight_name(char *name){
        strcpy(this->flight_name, name);
    }
    void set_value(int value){
        this->value = value;
    }
    char *get_flight_name(){
        return this->flight_name;
    }
    int get_value(){
        return this->value;
    }

};

class Customer : public People{
    protected:
    int quantity;
    Ticket *ticket;
    public:
    void set_name(char *name){
        People::setName(name);
    }
    void set_id(int id){
        People::set_ID(id);
    }
    void set_quantity(int number){
        this->quantity = number;
        ticket = new Ticket[quantity];
        char fname[40];
        string value;
        for(int i = 0; i < this->quantity; i++){
            cout << "Input flight name " << i+1 << ": ";
            cin.getline(fname, 40);
            ticket[i].set_flight_name(fname);
            fflush(stdin);
            cout << "Input value for ticket " << i+1 << ": ";
            cin >> value;
            ticket[i].set_value(stoi(value));
            fflush(stdin);
        }
    }
}