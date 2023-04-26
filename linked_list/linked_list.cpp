//林鉉閎(b090340032)
//2021/12/6
// LINKLIST
#include<iostream>
#include<cstdlib>
using namespace std;
class poly
{
	public:
		poly(){ coef=0;	exp=0 ;next=NULL;}
		poly(int coef,int exp,poly* next) { coef=coef;	exp=exp ;next=next;}
		int getcoef(){	return coef;	}
		int getexp(){	return exp	;}
		poly* getnext()	{	return next;	}
		void adjust_data(int a,int b){	coef=a; exp=b;	}		//change private int
		void adjust_next(poly* a){	next=a;	}	//cause stack->last=top can't do that(beacuse of lvalue),so make a function
	private:
		int coef;
		int exp;
		poly *next;
		
};
class caselink					//caselink consists of poly *top_p,poly *top_q	,	poly *top_add	,	poly *top_mul	, caselink *nextcase
{
	public:
		caselink()	{	top_p=NULL;top_q=NULL;top_add=NULL;top_mul=NULL;	}
		caselink* getnextcase(){	return nextcase;	}
		poly* gettop_p(){	return top_p;	}
		poly* gettop_q(){	return top_q;	}
		poly* gettop_add(){	return top_add;	}
		poly* gettop_mul(){	return top_mul;	}
		void adjust_poly_top_p(poly *a){	top_p=a;	}
		void adjust_poly_top_q(poly *b){	top_q=b;	}
		void adjust_poly_top_add(poly *c){	top_add=c;	}	
		void adjust_poly_top_mul(poly *d){	top_mul=d;	}
		void adjust_nextcase(caselink *e)	{	nextcase=e;	}
	private:
		poly *top_p;
		poly *top_q;
		poly *top_add;
		poly *top_mul; 
		caselink *nextcase;
};
poly* sortingplusrepeat(poly *first);    //sorting and deleting repeated 0
poly* operator +(poly &p,poly &q);
poly* operator *(poly &p,poly &q);	
void print(poly *first);
poly *temp_poly=NULL;		//store poly pointer
caselink *temp_case=NULL;	//store case pointer
int main()
{
	int c,e;
	int p,q;
	caselink *top_case=new caselink();
	temp_case=top_case;
	caselink *now=NULL;
	do{
		cin>>p;
		
		if(p!=0)
		{
			poly *top_p=new poly();    //keep top_p
			temp_poly=top_p;
			for(int i=0;i<p;i++)
			{
				cin>>c>>e;
				temp_poly->adjust_data(c,e);
				if(i==p-1)
			   		 temp_poly->adjust_next(NULL);	//last one become NULL
				else
				{									//the old one point to new one
					poly *input=new poly();
					temp_poly->adjust_next(input);
					temp_poly=input;
				}
					
			}
			temp_case->adjust_poly_top_p(top_p);
		}
		cin>>q;
		if(q!=0)
		{
			poly *top_q=new poly();    //keep top_q
			temp_poly=top_q;
			for(int i=0;i<q;i++)
			{
				cin>>c>>e;
				temp_poly->adjust_data(c,e);
				if(i==q-1)
			   		 temp_poly->adjust_next(NULL);	//last one become NULL
				else
				{
					poly *input=new poly();
					temp_poly->adjust_next(input);
					temp_poly=input;
				}
					
			}
			temp_case->adjust_poly_top_q(top_q);
		}
		if(p!=0 || q!=0)			//if q or p has value
		{
			caselink *s=new caselink();
			temp_case->adjust_nextcase(s);
			now=temp_case;							//because if  it comes to the last case,use (caselink *now) store it
			temp_case=temp_case->getnextcase();		//this line will push new case
		}
		if(p==0 && q==0)
		{
			now->adjust_nextcase(NULL);        //if now is the last case ,put null into case
			delete temp_case;
		}	
	}while(p!= 0 || q!=0);
	temp_case=top_case;	
	while(temp_case!=NULL)                  //computation
	{
		sortingplusrepeat(temp_case->gettop_p());
		sortingplusrepeat(temp_case->gettop_q());
		poly *A=temp_case->gettop_p();
		poly *B=temp_case->gettop_q();
		poly *C,*D;
		C=*A + *B;
		D= (*A) * (*B);	
		temp_case->adjust_poly_top_add(C);
		temp_case->adjust_poly_top_mul(D);
		temp_case=temp_case->getnextcase();
	}
	temp_case=top_case;
	int n=0;
	while(temp_case!=NULL)				//print
	{
		n++;
		cout<<"case "<<n<<endl;
		cout<<"ADD"<<endl;		
		print(temp_case->gettop_add());
		cout<<"MUL"<<endl;
		print(temp_case->gettop_mul());
		temp_case=temp_case->getnextcase();
	}
}
poly* sortingplusrepeat(poly *first)
{
	poly *current=first;
	poly *tempfirst=first;
	int tempcoef,tempexp,check=0;
	if(first==NULL){}
	else if(first->getnext()==NULL){}
	else
	{
		while(tempfirst->getnext()!=NULL)	//n-1*n-1 times bubble sort
		{
			current=first;
			while(current->getnext()!=NULL)
			{
				if(current->getexp() < current->getnext()->getexp())
				{
					tempcoef=current->getnext()->getcoef();
					tempexp=current->getnext()->getexp();
					current->getnext()->adjust_data(current->getcoef(),current->getexp());
					current->adjust_data(tempcoef,tempexp);
				}
				current=current->getnext();
			}
		tempfirst=tempfirst->getnext();
		}
	}
	current=first;
	tempfirst=first;
	if(first==NULL){}
	else if(first->getnext()==NULL){}
	else										//if coef is same as the other delete
	{
		do{	
			check=0;
			current=first;
			while(current->getnext()!=NULL)
			{
				if(current->getexp() == current->getnext()->getexp())
				{
					 poly *temp=current->getnext();			
					 current->adjust_data(current->getcoef()+current->getnext()->getcoef(),current->getexp());
					 current->adjust_next(temp->getnext());
					 check=1;
					 delete temp;
					 break;
				}	
					current=current->getnext();
				
			}
			
		}while(check==1);
	}
	
	current=first;
	while(current!=NULL)				//delete 0
	{
		
		if(current->getcoef()==0)
		{
			
			if(first==current)			//0 is the current
			{
				poly* temp=current;
				current=current->getnext();
				first=first->getnext();
				delete temp;
			}
			else  						//0 is the current->next
			{
				
				poly* temp2=NULL;
				for(poly* c=first;c->getnext()!=NULL;c=c->getnext())
				{
					
					if(c->getnext()==current)
					{
				
						poly* temp=current;
						c->adjust_next(temp->getnext());
						temp2=c->getnext();
						delete temp;
						break;
					}
				}
				current=temp2;
			}
		}
		else current=current->getnext();
	}
	
	return first;	
}

void print(poly *first)
{
	poly *current=first;
	if(current==NULL)
	{
		cout<<"0 0" <<endl;
		return;
	}
	while(current!=NULL)
	{
		cout<<current->getcoef()<<" "<<current->getexp()<<endl;
		current=current->getnext();
	}
}
poly* operator +(poly &p,poly &q)
{
	poly* tempp=&p;
	poly* tempq=&q;
	poly *first=new poly(); //keep first
	poly *tempfirst=first;  
	
	int pnum=0,qnum=0;
	for(poly *current=tempp;current!=NULL;current=current->getnext()){
		pnum++;
	}
	for(poly *current=tempq;current!=NULL;current=current->getnext()){
		qnum++;
	}
	for(int i=0;i<pnum;i++)
	{	
				tempfirst->adjust_data(tempp->getcoef(),tempp->getexp());
				tempp=tempp->getnext();
					poly *input=new poly();
					tempfirst->adjust_next(input);
					tempfirst=input;
					
	}
	for(int i=0;i<qnum;i++)
	{	
				tempfirst->adjust_data(tempq->getcoef(),tempq->getexp());
				tempq=tempq->getnext();
				if(i==qnum-1)
			   		 tempfirst->adjust_next(NULL);	//last one become NULL
				else
				{
					poly *input=new poly();
					tempfirst->adjust_next(input);
					tempfirst=input;
				}			
	}
	return first;
}
poly* operator *(poly &p,poly &q)
{

	poly *first=new poly(); //keep first
	poly *tempfirst=first;  
	
	for(poly* tempp=&p;tempp!=NULL;tempp=tempp->getnext())
	{	
		for(poly* tempq=&q;tempq!=NULL;tempq=tempq->getnext()){
			tempfirst->adjust_data(tempp->getcoef()*tempq->getcoef(),tempp->getexp()+tempq->getexp());
			if(tempp->getnext()==NULL && tempq->getnext()==NULL)
		   		 tempfirst->adjust_next(NULL);	//last one become NULL
			else
			{
				poly *input=new poly();
				tempfirst->adjust_next(input);
				tempfirst=input;
			}
		}

	}
	first=sortingplusrepeat(first);
	return first;
}




