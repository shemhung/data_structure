//(b093040032)  林鉉閎
//2021/10/5
//hw1.1
#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;
void magicsquare(int);
// 		main		//
 int main()
 {
 
	 magicsquare(1);          
	 cout<<endl;
	 magicsquare(3);
	cout<<endl;
	 magicsquare(5);
	cout<<endl;
	 magicsquare(7);
	 	 cout<<endl;
	 magicsquare(9);
	 
 }
 // function
void magicsquare(int factorial)
 {
 	int  arr[factorial][factorial];
 	//Initializing the lower left corner (x,y) as (0,0)
 	//(x,y)=((factorial-1)/2),factorial-1)=1
 	int x=(factorial-1)/2;int y=factorial-1;  
 	int count=1;				
 	//initialization
 	for(int i=0;i<factorial;i++)
 	{
 		for(int j=0;j<factorial;j++)
 		{
 			arr[i][j]=0;
		}
	}
 	arr[x][y]=1;
 	//run (factorial*factorial) times
 	while(count<factorial*factorial)
 	{
 		count++;
 		//if(x,y) is in the the upper left corner ，check rules
 		if(x-1==-1&&y+1==factorial)
 		{
 			if(arr[factorial-1][0]==0)
 			{
 				arr[factorial-1][0]=count;
 				x=factorial-1;y=0;
			}
 			else
 			{
 				arr[x][y-1]=count;
 				y=y-1;	
			}
 			
		}
		//if(x,y) is in the the upper side ，check rules
		else if(y+1==factorial)
		{
			if(arr[x-1][0]==0)
			{
				arr[x-1][0]=count;
				x=x-1;y=0;
			}
			else
			{
				arr[x][y-1]=count;
				y=y-1;
		    }
		}
		//if(x,y) is in the the left side ，check rules
		else if(x-1==-1)
		{
			if(arr[factorial-1][y+1]==0)
			{
				arr[factorial-1][y+1]=count;
				x=factorial-1;y=y+1;
			}
			else
			{
				arr[x][y-1]=count;
				y=y-1;
			}
		}
		//otherwise ，check rules
		else
		{
			if(arr[x-1][y+1]==0)
			{
				arr[x-1][y+1]=count;
				x=x-1;y=y+1;
			}
			else
			{
				arr[x][y-1]=count;
				y=y-1;
			}
			
		}
	}
	//print all the result
	for(int j=factorial-1;j>=0;j--)
	{
		for(int i=0;i<factorial;i++)
		{
			cout<<setw(2)<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}    
 