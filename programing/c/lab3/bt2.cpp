#include <iostream>
#include <string.h>
#include <math.h>
#include <string>
#define max 10 // The maximum amount of student the list can contain 

using namespace std;
class People{
    protected: 
    char name[40];
    int id; 
    public: 
    void setname(char* name){
		strcpy(this->name,name);
	}
	void set_id(int id){
		this->id = id; 
	}
	char* getName(){
		return name;
	}
	
	int get_id(){
		return id;
	}

};

class Ticket{
    private:
    char flightName[40];
    int value;
    public:
    void setFlightName(char* name){
		strcpy(flightName,name);
	}
	void set_value(int value){
		this->value = value; 
	}
	char* getFlightName(){
		return flightName;
	}
	
	int get_value(){
		return value;
	}

};

class Customer : public People{
    protected:
    int Ticket_quantity; 
    Ticket* ticket;
    public :
    void setName(char* name){
        People::setname(name);
    }

    void setID(int id){
        People::set_id(id);
    }

    void setQuantity(int number){
        Ticket_quantity = number;
        ticket = new Ticket[Ticket_quantity];
        char fname[40]; 
        string value; 
        for(int i = 0; i< number ; i++ ){
        cout<<"Input flight name for ticket " <<i+1<<": " ;
		cin.getline(fname,40);
        ticket[i].setFlightName(fname);
		fflush(stdin);
		cout<<"Input value for ticket"<<i+1<<": ";
		cin>>value;
		ticket[i].set_value(stoi(value));
		fflush(stdin);
        }
    }

    int option1(){
        int sum = 0;
        for(int i = 0 ;i < Ticket_quantity; i++){
            sum += ticket[i].get_value();
        }
        return sum;
    }

};


int main(){   
string numPeople;
char name[40]; 
string id, value;
cout<<"How many customers ?";
cin>>numPeople;
fflush(stdin);
Customer list[stoi(numPeople)];
string numberOfTickets[stoi(numPeople)];
for(int i = 0; i < stoi(numPeople) ;i++){
    cout<<"Input details for Customer "<<i+1<<endl;
    cout<<"Name ? ";
    cin.getline(name,40);
    list[i].setName(name);
    fflush(stdin);
    cout<<"ID? "; 
    cin>>id;
    list[i].set_id(stoi(id));
    fflush(stdin);
    cout<<"How many tickets ? "; 
    cin>>numberOfTickets[i];
    fflush(stdin);
    list[i].setQuantity(stoi(numberOfTickets[i]));
    fflush(stdin);

}
string option; 
cout<<"Select option : ";
cin>>option; 
fflush(stdin);
if(option == "1"){
    string temp; // id
    cout<<"Which customers ? ";
    cin>>temp;;
    fflush(stdin);
    for(int i = 0; i< stoi(numPeople) ;i++ ){
        cout<<"list id is "<<list[i].get_id()<<endl;
        if(list[i].get_id() == stoi(temp)){
            cout<<"list id is "<<list[i].get_id()<<endl;
            cout<<"Sum value of the customer : "<<list[i].option1();
        }
    }

    cout<<"fff \n";

}
else if(option == "2"){
    char flightname[40]; 
    cout<<"Which flight ?"; 
    cin.getline(flightname,40);
    fflush(stdin);
    cout<<"The flight has customers : \n"; 
    for(int i =0 ; i < stoi(numPeople) ;i++ ){
        if(strcmp(list[i].getName() , flightname) == 0  ) cout<<list[i].getName()<<endl;
    }
}



	return 0;
}

