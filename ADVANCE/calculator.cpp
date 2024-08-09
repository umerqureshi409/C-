#include <iostream>
using namespace std;
int main()
{
    int num1 , num2;
    float obt_marks , total_marks;
    char x , y ;
    
    cout<<"For Normal Calculation PRESS 'N' : "<<endl;
   
    cout<<"FOR PERCENTAGE COUNT PRESS 'Z' : "<<endl;
    cin>>y;
    if (y=='N')
    {cout<<"Enter Num 1 : "<<endl;
     cin>>num1;
    cout<<"Enter Num 2 : "<<endl;
    cin>>num2;
    cout<<"PRESS 'A' FOR ADDITION : "<<endl;
    cout<<"PRESS 'B' FOR SUBTRACTION : "<<endl;
    cout<<"PRESS 'C' FOR MULTIPLICATION : "<<endl;
    cout<<"PRESS 'D' FOR DIVISION : "<<endl;
    cout<<"PRESS 'E' FOR REMINDER : "<<endl;
  
    cin>>x;
    if (x=='A')
    cout<<"THE SUM IS : "<<num1+num2<<endl;
    else if (x=='B')
    cout<<"THE SUBTRACTION IS : "<<num1-num2<<endl;
    else if (x=='C')
    cout<<"THE MULTIPLICATION IS : "<<num1*num2<<endl;
    else if (x=='D')
    cout<<"THE DIVISION IS : "<<(float)num1/num2<<endl;
    else if (x=='E')
    cout<<"THE REMINDER IS : "<<num1%num2<<endl;
    else
    {
        cout<<"Worng Input"<<endl;
    }

    }
   else if (y=='Z')
   {
    char o;
    cout<<"PRESS S FOR RESULT PERCENTAGE : "<<endl;
    cout<<"PRESS Q FOR PROFIT PERCENTAGE : "<<endl;
    cin>>o;
    if(o=='S'){
     cout<<"ENTER THE OBTAINED MARKS : "<<endl;
    cin>>obt_marks;
    cout<<"ENTER THE TOTAL MARKS : "<<endl;
    cin>>total_marks;
    float percentage=obt_marks/total_marks*100;

    cout<<"THE PERCENTAGE IS : "<<percentage<<"%"<<endl;
    string grade;
  
    if(percentage>=80){
          grade = "A+";
    }
    else if(percentage>=70){
          grade = "A";
    }
    else if(percentage>=60){
          grade = "B";
    }
    else if(percentage >=50){
        grade = "C" ;
    }
    else{
        grade = "FAIL";
    }
    cout<<"YOUR GRADE IS : "<<grade;


    }
    else if(o=='Q'){
    cout<<"ENTER THE TOTAL AMOUNT : "<<endl;
    cin>>obt_marks;
    cout<<"ENTER THE PROFIT PERCENTAGE : "<<endl;
    cin>>total_marks;
    float percentage=obt_marks/100*total_marks;

    cout<<"THE PERCENTAGE IS : "<<percentage<<endl;

    }
    else{
        cout<<"WRONG KEYBORAD INPUT";
    }
   }
       else{
        cout<<"WRONG KEYBOARD INPUT";
        }

   return 0;
   
}