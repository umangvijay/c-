//write a program to multiple ooperstions
#include<iostream>
using namespace std;
int main()
{
    int a,b;
    int x;
    cout << "\n \n Enter the operation you want to perform(+(1)-(2)*(3)/(4)%(5))"<<endl;

    cin >> x;
    cout << "Enter two  number\n ";
    cin >>a>>b;

    if (x==1)
    {
        cout<< "sum : "<<a+b;
    }
    else if(x==2) {
        cout <<"subtract : "<<a-b;
    }
    else if(x==3) {
        cout <<"multiply : "<<a*b;
    }
    else 
    {
        cout<< "divide : "<<a/b;
    }
    return 0;

}
