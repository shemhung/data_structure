//林鉉閎(b093040032)
//2021/10/5
//hw1.2:factorial
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
// main   //
int main()
{
	int input,n,temp,digitnum=0,everydigitnum=0;
	//input number
	vector<int>num; 
	//numbers of digits
	vector<int> digit ;
	//input number 
	while(1)
	{
		cin>>input;
		if(input==0)
			break;
		num.push_back(input);
	}

	for(int i=0;i<num.size();i++)
	{
		n=1;digitnum=0;
		digit.push_back(1);
		cout<<"1!=1"<<endl;
		//going through how many testcase
		while(n<num[i])
		{
			
			//each digit multiply (n+1)	
			for( digitnum=0;digitnum<=digit.size()-1;digitnum++)
			{
				digit[digitnum]=digit[digitnum]*(n+1);
			}
			//if (each digit >10 )  move to next digit)
			for(digitnum=0;digitnum<=digit.size()-1;digitnum++)
			{
				if(digit[digitnum]>=10)
				{
					//if digit is the leftest   then push_back
					if(digitnum==digit.size()-1)
					{
				
						digit.push_back(digit[digitnum]/10);
						digit[digitnum]=digit[digitnum]%10;
				
					}
					//otherwise follow the rules
					else
					{
						temp=digit[digitnum]/10;
						digit[digitnum]=digit[digitnum]%10;
				
						digit[digitnum+1]=digit[digitnum+1]+temp;	
					}	
				}
			}
			n++;	
			//print the process of factorial 1! to n!
			cout<<n<<"!=";
			for(int digitnum=digit.size()-1;digitnum>=0;digitnum--)
			{	
				cout<<digit[digitnum];
			}
			cout<<endl;
		}
		cout<<endl;
		//clear the vector and continue to store next vector
		digit.clear();
	}
}