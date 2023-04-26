//�@�� : B093040030  �d�ꦨ 
//���g��� : Oct. 13, 2021 
//���{�����\�� : �ϥ�stack��X��v�ѽL�W�M�h���ʪ�����
#include<iostream>
#include<iomanip>
using namespace std;
typedef struct stack{      //�x�s�y�Фθ��|�����c 
		int i;           //�a�y�Э� 
		int j;           //��Э� 
		int move;        // ���ʤ�V 
		stack *next;     //�e�@�ӵ��c����} 
}stack;
stack *top = NULL;       		//���쵲�c�̤W�h������ 
void push(int,int,int);         //�N�Ȧs�J���c�� 
void pop(int&,int&,int&);       //�N�ȱq���c�����X 
bool empty();                   //�P�_���c�O�_�w�� 
int main(){
	int number[8][2] = {{1, -2}, {2, -1}, {2, 1},{1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}};  //�i���ʪ���V 
	int x = 0,y = 0;        //�ثe�M�h�Ҧb��m 
	int emp = 0;            //�x�s���c�O�_�w�� 
	int k = 0;              //���ʤ�V 
	for(int i = 1; i <= 6; i++){   //�q1x1��6x6 
		cout << "n = " << i << endl;
		emp = 0;                //�N�ȳ���l�Ƭ�0 
		x = 0;
		y = 0;
		k = 0;
		int **array = new int*[i];  //�غc�@�ӰʺA�}�C 
		for(int g = 0; g <i; g++){
			array[g] = new int[i];
		}  
		for(int a = 0; a < i; a++){      //�N�}�C�����ȳ��]��0 
			for(int b= 0; b < i; b++){
				array[a][b] = 0;
			}
		}
		array[0][0] = 1;   //���W�����_�I��1 
		for(int j = 2; j <= i * i; j++){         //�n��J���Ʀr�q2�}�l,�@����i*i 
			while(k < 8){                        //8�Ӥ�V���n���� 
				if((x + number[k][0]) >= 0 && (x + number[k][0]) < i && (y + number[k][1]) >= 0 && (y + number[k][1]) < i 
				&& array[x+number[k][0]][y+number[k][1]] == 0)   //�Y�S���W�X��ɦӥB�٨S��J�ƭȫh�i��push 
				{
					push(x+1,y+1,k+1);    //�N�ƭ�push�i���c�� 
					x += number[k][0];    //�a�y�в��ʦܤU�Ӧ�m 
					y += number[k][1];    //��в��ʦܤU�Ӧ�m 
					array[x][y] = j;      //�N�ƭȶ�J�}�C�� 
					k = 0;                 
					break;
				}
				if(k == 7){              //������V�����ਫ 
					if(!empty()){         //�p�G���c����,�h�i��pop 
						array[x][y] = 0;     //�Narray�����ȭ��]��0 
						pop(x,y,k);            //�N��pop�X�� 
						j -= 2;                //�h�^�W�@�ӭ� 
						while(k == 8){         //�p�Gpop�X�Ӫ��Ȥw�g�L�k����,�h�~��i��pop 
							array[x][y] = 0;
							pop(x,y,k);
							j--;
						}
					}
					else     //�}�C�w�� 
						emp = 1;
					break;
				}
				k++;
			}
			if(emp)    //�p�G�}�C�w�ūh���X�j�� 
				break;
		}
			cout << endl;
			if(emp)         //�p�G�}�C�w��,�h�L�X�L�� 
				cout << "no solution" << endl;
			else{        //�N���G�L�X 
				for(int m = 0; m < i; m++){
					for(int n = 0; n < i; n++){
						cout << setw(2) << array[m][n] << " ";
					}
					cout << endl;
					}
			}
			cout << endl;
			for(int m = 0; m < i; m++){      //�R���ʺA�}�C 
				delete [] array[m];
			}
			delete [] array;
	}
	return 0;
}
void push(int x, int y, int z){
	stack *input = new stack;   //�سy�@�ӷs��stack 
	input->i = x;               //�N�Ȧs�J���c�� 
	input->j = y;
	input->move = z;
	input->next = top;        //�s�}�C���쪺��}�O�쥻������ 
	top = input;              //�s�}�C�ܬ��s������ 
}
void pop(int &x,int &y,int &k){
	stack *temp;        //�إߤ@�ӼȦs��stack 
	temp = top;          
	x = temp->i ;       
	y = temp->j ;
	k = temp->move;
	x --;
	y --;
	top = top->next;     //�Ntop����U�@�Ӧ�m 
	delete temp;
}
bool empty(){              //�P�_�}�C�O�_�w�� 
	if(top == NULL)
		return true;
	return false;
}
