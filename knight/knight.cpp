//作者 : B093040030  吳國成 
//撰寫日期 : Oct. 13, 2021 
//本程式之功能 : 使用stack找出西洋棋盤上騎士移動的順序
#include<iostream>
#include<iomanip>
using namespace std;
typedef struct stack{      //儲存座標及路徑的結構 
		int i;           //縱座標值 
		int j;           //橫坐標值 
		int move;        // 移動方向 
		stack *next;     //前一個結構的位址 
}stack;
stack *top = NULL;       		//指到結構最上層的指標 
void push(int,int,int);         //將值存入結構中 
void pop(int&,int&,int&);       //將值從結構中取出 
bool empty();                   //判斷結構是否已空 
int main(){
	int number[8][2] = {{1, -2}, {2, -1}, {2, 1},{1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};  //可移動的方向 
	int x = 0,y = 0;        //目前騎士所在位置 
	int emp = 0;            //儲存結構是否已空 
	int k = 0;              //移動方向 
	for(int i = 1; i <= 6; i++){   //從1x1到6x6 
		cout << "n = " << i << endl;
		emp = 0;                //將值都初始化為0 
		x = 0;
		y = 0;
		k = 0;
		int **array = new int*[i];  //建構一個動態陣列 
		for(int g = 0; g <i; g++){
			array[g] = new int[i];
		}  
		for(int a = 0; a < i; a++){      //將陣列中的值都設為0 
			for(int b= 0; b < i; b++){
				array[a][b] = 0;
			}
		}
		array[0][0] = 1;   //左上角的起點為1 
		for(int j = 2; j <= i * i; j++){         //要填入的數字從2開始,一直到i*i 
			while(k < 8){                        //8個方向都要嘗試 
				if((x + number[k][0]) >= 0 && (x + number[k][0]) < i && (y + number[k][1]) >= 0 && (y + number[k][1]) < i 
				&& array[x+number[k][0]][y+number[k][1]] == 0)   //若沒有超出邊界而且還沒填入數值則進行push 
				{
					push(x+1,y+1,k+1);    //將數值push進結構中 
					x += number[k][0];    //縱座標移動至下個位置 
					y += number[k][1];    //橫坐標移動至下個位置 
					array[x][y] = j;      //將數值填入陣列中 
					k = 0;                 
					break;
				}
				if(k == 7){              //全部方向都不能走 
					if(!empty()){         //如果結構未空,則進行pop 
						array[x][y] = 0;     //將array中的值重設為0 
						pop(x,y,k);            //將值pop出來 
						j -= 2;                //退回上一個值 
						while(k == 8){         //如果pop出來的值已經無法移動,則繼續進行pop 
							array[x][y] = 0;
							pop(x,y,k);
							j--;
						}
					}
					else     //陣列已空 
						emp = 1;
					break;
				}
				k++;
			}
			if(emp)    //如果陣列已空則跳出迴圈 
				break;
		}
			cout << endl;
			if(emp)         //如果陣列已空,則印出無解 
				cout << "no solution" << endl;
			else{        //將結果印出 
				for(int m = 0; m < i; m++){
					for(int n = 0; n < i; n++){
						cout << setw(2) << array[m][n] << " ";
					}
					cout << endl;
					}
			}
			cout << endl;
			for(int m = 0; m < i; m++){      //刪除動態陣列 
				delete [] array[m];
			}
			delete [] array;
	}
	return 0;
}
void push(int x, int y, int z){
	stack *input = new stack;   //建造一個新的stack 
	input->i = x;               //將值存入結構中 
	input->j = y;
	input->move = z;
	input->next = top;        //新陣列指到的位址是原本的頂端 
	top = input;              //新陣列變為新的頂端 
}
void pop(int &x,int &y,int &k){
	stack *temp;        //建立一個暫存的stack 
	temp = top;          
	x = temp->i ;       
	y = temp->j ;
	k = temp->move;
	x --;
	y --;
	top = top->next;     //將top移到下一個位置 
	delete temp;
}
bool empty(){              //判斷陣列是否已空 
	if(top == NULL)
		return true;
	return false;
}
