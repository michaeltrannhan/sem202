#include <iostream>
using namespace std;

class Rectangle{
    protected: 
        float width;
        float height;
    public:
        Rectangle()
        {
            this->width = this->height= 0;
        }
        Rectangle(float width, float height)
        {
            this->width = width;
            this->height = height;
        }

        ~Rectangle();

        float getArea()
        {
            return this->height * this->width;
        }

};
 
int main()
{
    int num;
    float width, height ;
    cout <<"How many rectangles? ";
    cin>> num;
    if (num <1 || num >100)
    {
        cout <<"Out of range!";
    }

    Rectangle* obj[num];
    for (int  i= 0; i < num;i++ )
    {
        cout << "----------------\n";
        cout << "Input width and height for rectangle "<< i+1 <<endl;
        cout << "Width:" << endl;
        cin >> width;
        cout << "Height" << endl;
        cin >> height;

        obj[i] = new Rectangle(width, height);
    }
    cout << "====================\n";
    for(int i = 0 ; i < num; i++)
    {
        cout << "The area of rectangle "<< i+1 << ": "<< obj[i]->getArea() << endl;
    }
}