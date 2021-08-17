#include <iostream>

using namespace std;
int arr[150];
int arr1[150];
int idx = 0;
int idx1 = 0;
bool inRange(int limit)
{
    if (limit >= 10 && limit <= 150)
        return true;
    return false;
}

void printdiv()
{
    for (int i = 0; i <= idx; i++)
        cout << arr[i] << " ";
}

void div35(int limit)
{
    cout << "Numbers that are divisible by both 3 and 5:";
    for (int i = 1; i <= limit; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            arr[idx] = i;
            cout << arr[idx] << " ";
            idx++;
        }
        else
        {
            arr[idx1] = i;
            idx1++;
        }
    }
}

void sumdiv(int limit)
{
    int sum = 0;
    for (int i = 0; i <= limit; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
            sum = sum + arr[i];
    }
    cout << "Sum of numbers being divisible by either 3 or 5: " << sum << endl;
}

void notdiv(int limit)
{
    int count = 0; 
    cout<<"Numbers that are not divisible by 3 or 5 are : "; 
    for(int i = 0; i <= limit ;i++){
        if(i % 3 !=0 && i % 5 != 0 ){
            //cout<<i<<" ";
            count++;
        }
    }
    if(count == 0 ) cout<<"There are no numbers that are not divisible by 3 or 5 \n ";
    else{
        cout<<"The numbers that are not divisible by 3 or 5 is :" <<count<<endl;
    }
}

int main()
{
    int limit;
    label: cout << "Input a limit" << endl;
    cin>>limit;
    while(!inRange(limit)){
        cout << "Input is out of range !";
        goto label;
    }
    div35(limit);
    sumdiv(limit);
    notdiv(limit);
    return 0;
}