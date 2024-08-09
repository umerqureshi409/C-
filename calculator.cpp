#include <iostream>
using namespace std;
int main()
{
	int num1, num2;
	char x ,y , z ;
	float obt_marks, total_marks;
	cout<<"PRESS 'a' FOR BASIC CALCULATION "<<endl;
	cout<<"PRESS 'b' FOR PERCENTAGE CALCULATION "<<endl;
	cin>>x;
	if(x=='a') 
	{
		cout<<"ENTER 1st NUMBER  "<<endl;
		cin>>num1;
		cout<<"ENTER 2nd NUMBER  "<<endl;
		cin>>num2;
		
		cout<<"PRESS 'A' FOR ADDITION "<<endl;
		cout<<"PRESS 'B' FOR SUBTRACTION "<<endl;
		cout<<"PRESS 'C' FOR MULTIPLICATION "<<endl;
		cout<<"PRESS 'D' FOR DIVISION "<<endl;
		cout<<"PRESS 'E' FOR REMINDER "<<endl;
		cin>>y;
		if(y=='A')
		{
			cout<<"THE SUM IS : "<<num1+num2<<endl;
			
		}
		else if(y=='B')
		{
			cout<<"THE SUBTRACTION IS : "<<num1-num2<<endl;
			
		}
         
		else if(y=='C')
		{
			cout<<"THE MULTIPLICATION IS : "<<num1*num2<<endl;
			
		}
		else if(y=='D')
		{
			cout<<"THE DIVISION IS : "<<(float)num1/num2<<endl;
			
		}
        
        else if(y=='E')
		{
			cout<<"THE REMINDER IS : "<<num1%num2<<endl;
			
		}
		
		else
    {
    	cout<<"INVALID KEYBOARD INPUT";
	}
		

	}
	
	
	
	else if(x=='b')
	
	{
		cout<<"PRESS 'N' FOR RESULT PERCENTAGE "<<endl;
		cout<<"PRESS 'K' FOR DEDUCTION PERCENTAGE "<<endl;
		cin>>z;
		if(z=='N')
		{
		cout<<"ENTER OBTAINED MARKS "<<endl;
		cin>>obt_marks;
		cout<<"ENTER TOTAL MARKS "<<endl;
		cin>>total_marks;
		float percentage=obt_marks/total_marks*100;
		cout<<"THE PERCENTAGE IS : "<<percentage<<endl;
        
	    }
	    
	    else if(z=='K')
	    {
	    	cout<<"ENTER TOTAL AMOUNT "<<endl;
	    	cin>>total_marks;
	    	cout<<"ENTER DEDUCTION PERCENTAGE "<<endl;
	    	cin>>obt_marks;
	    	float deduct=total_marks/100*obt_marks;
	    	cout<<"THE AMOUNT IS : "<<deduct<<endl;
		}
		
		else
    {
    	cout<<"INVALID KEYBOARD INPUT";
	}
		
    }
    else
    {
    	cout<<"INVALID KEYBOARD INPUT";
	}
     

	
	return 0;
	
	
}