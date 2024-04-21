#include <iostream>
using namespace std;
int main(){

int n1, n2; //n1 and n2 are number 1 and number 2
cout<<"Enter Two Numbers: ";
cin>>n1>>n2;

char op;
cout<<"Select an operand(+,-,*,/): ";
cin>>op;        //Selection
switch (op){
    case '+':
    cout<<n1+n2<<endl;
    break;
    case '-':
    cout<<n1-n2<<endl;
    break;
    case '*':
    cout<<n1*n2<<endl;
    break;
    case '/':
    if(n2!=0){
    cout<<n1/n2<<endl;
    }
    else{
        cout<<"Error : division by zero";
    }
    break;
    default:
    cout<<"Operator not found!"<<endl; //either operand is selected wrong or not selescted

}
return 0;
}