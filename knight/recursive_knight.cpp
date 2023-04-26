//林鉉閎(b090340032)
//2021/11/5
// chess(recursive)
#include<iostream>
#include<iomanip>				//setw()
using namespace std;
int recursive(int ,int ,int ,int ,int ,int** );
bool check(int ,int **);
int main()
{	
		for(int n=1;n<=6;n++)
		{
				int **array=new int*[n];  // initialation
			for(int j=0;j<n;j++)
			{
				array[j]=new int[n];
			}
			for(int k=0;k<n;k++)
			{
				for(int l=0;l<n;l++)
				{
					array[k][l]=0;
				}
			}
			recursive(1,n,0,0,0,array);
			if(check(n,array))					//check solution
			{
				cout<<" n ="<<n<<endl;
				for(int t1=0;t1<n;t1++)
			    {
					for(int t2=0;t2<n;t2++)
					{
						cout<<setw(2)<<array[t1][t2]<<" ";
					}
					cout<<endl;
					
				}
			}
			else
				cout<<"n = "<<n<<" no solution"<<endl;
		}
}
int recursive(int now,int n,int i,int j,int d,int **array)
{		
		if(d>8)									//direction>8,end recursion
		{return 0;}
		else if(i<0 || i>=n || j<0 ||  j>=n )   //out of border, end recursion
		{return 0;}
		else if(array[i][j]!=0 )				//if digit has already been put,end recursion
		{return 0;}
		else	
		{
			//	cout<<"push"<<endl;				
				array[i][j]=now; 
				if(now==n*n)					//if digit has added to n*n,return 1
				{
					return 1;
				}
				now++;   	
				d=0;					
				/*for(int t1=0;t1<n;t1++)
				{
					for(int t2=0;t2<n;t2++)
					{
					cout<<setw(2)<<array[t1][t2]<<" ";
					}
					cout<<endl;
					
				}*/
				if((recursive(now,n,i-2,j+1,d+1,array))==1) return 1;		//if solution return 1 ,end recursion
				if((recursive(now,n,i-1,j+2,d+2,array))==1 )return 1;		//if solution return 1 ,end recursion		
				if((recursive(now,n,i+1,j+2,d+3,array))==1) return 1;		//if solution return 1 ,end recursion
				if((recursive(now,n,i+2,j+1,d+4,array))==1) return 1;		//if solution return 1 ,end recursion
				if((recursive(now,n,i+2,j-1,d+5,array))==1) return 1;		//if solution return 1 ,end recursion
				if((recursive(now,n,i+1,j-2,d+6,array))==1) return 1;		//if solution return 1 ,end recursion
				if((recursive(now,n,i-1,j-2,d+7,array))==1) return 1;		//if solution return 1 ,end recursion	
				if((recursive(now,n,i-2,j-1,d+8,array))==1 )return 1;		//if solution return 1 ,end recursion
				array[i][j]=0;
		//	cout<<now<<" "<<i+1<<" "<<j+1<<" "<<d<<""<<endl;
		//	cout<<"pop"<<endl;
		
		/*	for(int t1=0;t1<n;t1++)
			{
				for(int t2=0;t2<n;t2++)
				{
					cout<<setw(2)<<array[t1][t2]<<" ";
				}
					cout<<endl;
			}	*/
	}
	return 0;
}
bool check(int n,int **array)			// check if there is an 0,return false
{
	for(int t1=0;t1<n;t1++)
	{
		for(int t2=0;t2<n;t2++)
		{
			if(array[t1][t2]==0)
			{
				return false;
			}
		}
	}
	return true;
}
