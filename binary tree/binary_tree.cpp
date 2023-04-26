//林鉉閎(b093040032)
//20201/12/8
//binary seatch tree
#include<iostream>
using namespace std;
class treenode
{
	public:
		treenode(){	data=0; left=NULL; 	right=NULL;	}
		treenode(int d){ data=d;	left=NULL;	right=NULL; }
		int getdata(){	return data ;	}
		void adjust_data(int d){	data=d;	}
		void adjust_left(treenode *t){	left=t;	}
		void adjust_right(treenode *t){	right=t; }
		treenode* getleft(){	return left;	}
		treenode* getright(){	return right;	}
	private:
		int data;
		treenode *left;
		treenode *right;
};
class casetree
{
	public:
		casetree(){	root=NULL;nextcase=NULL;	}
		void insertandremove(int d)
		{
			int repeat=0;
			treenode *previous=	NULL;
			treenode *current=root;
			treenode *temp=new treenode(d);
			if(root==NULL)		//if root null push
			{
				root=temp;	
			}
			else
			{
				while(current!=NULL)    //insert new data
				{
					if(d>current->getdata())  //d >data
					{
						if(current->getright()==NULL)	//if *right is null,then push
						{
							current->adjust_right(temp);
							previous=current;
							current=current->getright();
							break;
						}
							
						else
						{
							previous=current;
							current=current->getright();
						}
													
					}
					else if(d<current->getdata())   //d<data
					{
						if(current->getleft()==NULL)	//if *left is null,then push
						{
							current->adjust_left(temp);
							previous=current;
							current=current->getleft();
							break;
						}	
						else
						{
							previous=current;
							current=current->getleft();
						}				
					}
					else
					{
						repeat=1;
						break;						//d==current->getdata()->repeated ,then break
					}	
				}
			}
			//printnode(root);
			if(repeat==1)
			{	
			    if(current->getleft()==NULL && current->getright()==NULL )		//leaf node
				{
					if(current==root)
					{
						delete current;
						root=NULL;
					}
					else
					{
						if(current->getdata()>previous->getdata())
							previous->adjust_right(NULL);
						else
							previous->adjust_left(NULL);
						delete current;
					}	
				}
				else if((current->getleft()==NULL &&current->getright()!=NULL) ||(current->getleft()!=NULL &&current->getright()==NULL)) // only one son
				{
					if(current==root)
					{
						if(root->getleft()!=NULL)
							root=root->getleft();
						else
							root=root->getright();
						delete current;
					}
					else
					{
						if(current->getleft()!=NULL)				//current->left is not NULL
						{
							if(current->getdata()<previous->getdata())  //data(current)<data(previous)
							{
								previous->adjust_left(current->getleft());
								delete current;
							}
							else									//data(current)>data(previous)
							{
								previous->adjust_right(current->getleft());
								delete current;
							}		
						}
						else									//current->right is not NULL
						{
							if(current->getdata()>previous->getdata())  //data(current)>data(previous)
							{
								previous->adjust_right(current->getright());
								delete current;
							}
							else									//data(current)<data(previous)
							{
								previous->adjust_left(current->getright());
								delete current;
							}
						}	
						
					}
				}
				else				//   two son 
				{
					int tempdata;
					treenode *tempcurrent=current;
					treenode *previous=current;
					current=current->getright();
					while(current->getleft()!=NULL)
					{
						previous=current;
						current=current->getleft();
					}
					tempdata=current->getdata();        //the right subtree'leftest value
					if(current->getleft()==NULL && current->getright()==NULL )		//leaf node
					{
					
						if(current->getdata()>previous->getdata())
							previous->adjust_right(NULL);
						else
							previous->adjust_left(NULL);
						delete current;
					}
					else if((current->getleft()==NULL &&current->getright()!=NULL) ||(current->getleft()!=NULL &&current->getright()==NULL)) // only one son
					{
						
						if(current->getleft()!=NULL)				//current->left is not NULL
						{
							if(current->getdata()<previous->getdata())  //data(current)<data(previous)
							{
								previous->adjust_left(current->getleft());
								delete current;
							}
							else									//data(current)>data(previous)
							{
								previous->adjust_right(current->getleft());
								delete current;
							}
							
						}
						else									//current->right is not NULL
						{
							if(current->getdata()>previous->getdata())  //data(current)>data(previous)
							{
								previous->adjust_right(current->getright());
								delete current;
							}
							else									//data(current)<data(previous)
							{
								previous->adjust_left(current->getright());
								delete current;
							}
						}
					}
					tempcurrent->adjust_data(tempdata);
				}
			}
		}
		void printnode(treenode *cur)
		{	
			if(cur)
			{
				printnode(cur->getleft());
				cout<<" "<<cur->getdata()<<" ";
				printnode(cur->getright());
			}	
		}
		void printleft(treenode *cur)
		{	
			if(cur)
			{
				printleft(cur->getleft());
				
			if(cur->getleft()==NULL)
					cout<<" "<<"0"<<" ";
			else
					cout<<" "<<cur->getleft()->getdata()<<" ";
		
				printleft(cur->getright());
			}	
		}
		void printright(treenode *cur)
		{	
			if(cur)
			{
				printright(cur->getleft());
				if(cur->getright()==NULL)
					cout<<" "<<"0"<<" ";
				else
					cout<<" "<<cur->getright()->getdata()<<" ";
				printright(cur->getright());
			}	
		}
		void adjust_nextcase(casetree* n){	nextcase=n;	}
		treenode* getroot(){	return root;	}
		casetree* getnextcase(){	return nextcase;	}
	private:
		treenode *root;				//the root
		casetree *nextcase;  		//many case
};

int main()
{
	int value;
	casetree *temp_case;
	casetree *now_case;
	casetree *top_case=new casetree();
	temp_case=top_case;
	while(cin>>value)
	{
		if(value==-1)
		{
			casetree *newcase=new casetree();
			temp_case->adjust_nextcase(newcase);
			now_case=temp_case;	
			temp_case=temp_case->getnextcase();
		}
		else
		{
			temp_case->insertandremove(value);	
		}
	}
	now_case->adjust_nextcase(NULL);
	temp_case=top_case;
	while(temp_case!=NULL)
	{	
		cout<<"node: ";
		temp_case->printnode(temp_case->getroot());
		cout<<"left: ";
		temp_case->printleft(temp_case->getroot());
		cout<<"right: ";
		temp_case->printright(temp_case->getroot());
		cout<<endl<<endl;
		temp_case=temp_case->getnextcase();
	}
}