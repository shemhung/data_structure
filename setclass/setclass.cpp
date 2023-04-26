//林鉉閎(b093040032)
//2021/10/14
// for set class
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
class TSet
{
	public:
		TSet();
		TSet(char* w);
		//allow to store string
		void repeat();
		//eliminate the repeated character
		friend  TSet operator+(const TSet& set1,const TSet& set2);
		friend  TSet operator*(const TSet& set1,const TSet& set2);
		friend  TSet operator-(const TSet& set1,const TSet& set2);
		friend bool operator >=( TSet& set1, TSet& set2);
		bool in(char w);
		// check if 'w' belong to this array
		friend ostream& operator <<(ostream& output,const TSet &set1 );
		friend istream& operator >>(istream& input, TSet& set1);
	private:
		char arr[256];
		//the set owns no more than 256 character
	
};
int main()
{
	int testcase;
	cin>>testcase;
	TSet A[testcase],B[testcase],C[testcase],D[testcase],E[testcase],F[testcase];
	char x[testcase];
	for(int i=0;i<testcase;i++)
	{
		
		cin.ignore();
		cin>>A[i]>>B[i];	
		cin>>x[i];
		
	}
	for(int i=0;i<testcase;i++)
	{
		A[i].repeat();
		B[i].repeat();
		C[i]=A[i]+B[i];
		C[i].repeat();
		D[i]=A[i]*B[i];
		D[i].repeat();
		E[i]=A[i]-B[i];
		F[i]=B[i]-A[i];
		cout<<"Test Case "<<(i+1)<<":"<<endl;
		cout<<"A: "<<A[i]<<endl;
		cout<<"B: "<<B[i]<<endl;
		cout<<"A+B: "<<C[i]<<endl;
		cout<<"A*B: "<<D[i]<<endl;
		cout<<"A-B: "<<E[i]<<endl;
		cout<<"B-A: "<<F[i]<<endl;
		if(A[i]>=B[i])
				cout<<"A contain B"<<endl;
		else
				cout<<"A does not contain B"<<endl;
		if(B[i]>=A[i])
				cout<<"B contain A"<<endl;
		else
				cout<<"B does not contain A"<<endl;
		if(A[i].in(x[i]))
				cout<<"'"<<x[i]<<"'"<<" is in A"<<endl;
		else
				cout<<"'"<<x[i]<<"'"<<" is not in A"<<endl;
		if(B[i].in(x[i]))
				cout<<"'"<<x[i]<<"'"<<" is in B"<<endl;
		else
				cout<<"'"<<x[i]<<""<<" is not in B"<<endl;
	}
	
		
}

TSet::TSet()
{
	arr[0]='\0';
	//initialization
};
TSet::TSet(char* w)
{
	string s1;
	for(int i=0;i<strlen(w);i++)
	{
		s1=s1+w[i];
	}
	strcpy(arr,s1.c_str());
	// transform string into character's array
};
void TSet::repeat()
{
	string w1="";
	w1=w1+arr[0];
	
		for(int i=1;i<strlen(arr);i++)
		{
			// compared to the last one and the next one 
			if(arr[i-1]==arr[i])
			{
				continue;
			}
			w1=w1+arr[i];
			// put into the non-repeated array
		}
		
		strcpy(arr,w1.c_str());	
}
ostream& operator<<(ostream& output,const TSet& set1)
{
	char temp;
	output<<"{";

	for(int i=0;i<strlen(set1.arr);i++)
	{
		output<<set1.arr[i];
	}
	//print the set's array
	output<<"}";
	return output;
}
istream& operator>>(istream& input,TSet& set1)
{
	input>>set1.arr;
	char temp;
	for(int i=0;i<strlen(set1.arr)-1;i++)
	{
		for(int j=0;j<strlen(set1.arr)-1-i;j++)
		{
			if(set1.arr[j]>set1.arr[j+1])
			{
				temp=set1.arr[j];
				set1.arr[j]=set1.arr[j+1];
				set1.arr[j+1]=temp;
			}
		}
	}
	//input and proceed bubble sort
	return input;
}
bool TSet::in(char w)
{
	for(int i=0;i<strlen(arr);i++)
	{
		if(w==arr[i])
			return true;
		//check the word in the array	
	}
	return false;
}
 TSet operator+(const TSet& set1 ,const TSet& set2 )
{
	char finalarr[256] = {},temp;
	for(int i=0;i<strlen(set1.arr);i++)
	{
		finalarr[i]=set1.arr[i];
	}
	for(int i=0;i<strlen(set2.arr);i++)
	{
		finalarr[i+strlen(set1.arr)]=set2.arr[i];
	}
	// 2 set addition
	for(int i=0;i<strlen(set1.arr)+strlen(set2.arr)-1;i++)
	{
		for(int j=0;j<strlen(set1.arr)+strlen(set2.arr)-1-i;j++)
		{
			if(finalarr[j]>finalarr[j+1])
			{
				temp=finalarr[j];
				finalarr[j]=finalarr[j+1];
				finalarr[j+1]=temp;
			}
		}
	}
	//bubble sort again
	return TSet(finalarr);
}

 TSet operator*(const TSet& set1 ,const TSet& set2 )
{
	string w1;
	char finalarr[256]={};
	for(int i=0;i<strlen(set1.arr);i++)
	{   //look through the set1's array
		for(int j=0;j<strlen(set2.arr);j++)
		{
			if(set1.arr[i]==set2.arr[j])
			{
				w1=w1+set1.arr[i];
			}
			//if (any character in set2's array ) equal to set1
		}
	}
	strcpy(finalarr,w1.c_str());
	return TSet(finalarr);
}

 TSet operator-(const TSet& set1 ,const TSet& set2 )
{
	string w1;
	TSet set3;
	int check=0;
	char finalarr[256]={};
	set3=set1*set2; 
	for(int i=0;i<strlen(set1.arr);i++)
	{
		check=0;
		for(int j=0;j<strlen(set3.arr);j++)
		{
			//if (set1's array)equal to (set3' array) ,then don't add it to the new string 
			if(set1.arr[i]==set3.arr[j])
			{
				check=1;
				break;
			}
			
		}
		//if not , then add it
		if(check==0)
		{
			w1=w1+set1.arr[i];
		}
	}
	strcpy(finalarr,w1.c_str());
	
	return TSet(finalarr);
}
bool operator>=( TSet& set1, TSet& set2)
{
	for(int i=0;i<strlen(set2.arr);i++)
	{
		// if each word in set2'array not belong to set1 ,return false
		if(!set1.in(set2.arr[i]))
		{
			return false;
		}
	}
		// if not ,return true
	return true;
}