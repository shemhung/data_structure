//林鉉閎(b093040032)
//20201/12/21
//hw7-sorting             
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<fstream>
#include<iomanip>
using namespace std;
void selectionsort(int arr[],int );
void merge(int arr[], int , int , int );
void mergesort(int arr[], int , int );
int getmax(int array[], int n);
void countingsort(int array[], int size, int place);
void radixsort(int array[], int size);
int compare (const void * a, const void * b);
void printarray(int arr[],int );
int main()
{
	srand(time(NULL));
	ifstream fin;
	ofstream fout;
	int n,filenum;
	
	
	fout.open("input.txt");
	cin>>n;
	fout<<n<<endl;
	for(int i=0;i<n;i++)
	{
		fout<<rand()<<endl;	
	}
	fout.close();
	
	fin.open("input.txt"); 				//read input.txt
	fin>>filenum;
	int *array0=(int *)malloc(filenum*sizeof(int));     //dynamic array
	int *array1=(int *)malloc(filenum*sizeof(int));
	int *array2=(int *)malloc(filenum*sizeof(int));
	int *array3=(int *)malloc(filenum*sizeof(int));
	int *array4=(int *)malloc(filenum*sizeof(int));
	for(int i=0;i<filenum;i++)
	{
		fin>>array0[i];
		array1[i]=array0[i];
		array2[i]=array0[i];
		array3[i]=array0[i];
		array4[i]=array0[i];
	}
	fin.close();
	
		clock_t start ,finish;							//selectionsort
		double time[5];
		start=clock();
		selectionsort(array0,filenum);
		finish=clock();
		time[0]= (double)(finish - start) / CLOCKS_PER_SEC;
		
		
		fout.open("outputA.txt");						
		fout<<"selectionsort"<<endl;
		for(int i=0;i<filenum;i++)
		{
		fout<<array0[i]<<endl;
		}
		fout.close();
	
		start=clock();								//mergesort
		mergesort(array1,0,filenum-1);
		finish=clock();
		time[1]= (double) (finish - start)/CLOCKS_PER_SEC ;
		fout.open("outputB.txt");
		fout<<"mergesort"<<endl;
		for(int i=0;i<filenum;i++)
		{
			fout<<array1[i]<<endl;
		}
		fout.close();
	
		start=clock();					//radixsort
		radixsort(array2,filenum);
		finish=clock();
		time[2]= (double)(finish - start) / CLOCKS_PER_SEC;
	
		fout.open("outputC.txt");
		fout<<"radixsort"<<endl;
		for(int i=0;i<filenum;i++)
		{
			fout<<array2[i]<<endl;
		}
		fout.close();
	
		start=clock();					//qsort
		qsort(array3,filenum,sizeof(int),compare); 
		finish=clock();
		time[3]= (double)(finish - start) / CLOCKS_PER_SEC;
		
		fout.open("outputD.txt");
		fout<<"qsort"<<endl;
		for(int i=0;i<filenum;i++)
		{
			fout<<array3[i]<<endl;
		}
		fout.close();
	
		start=clock();					//sort
		sort(array4,array4+filenum);
		finish=clock();
		time[4]= (double)(finish - start) / CLOCKS_PER_SEC;
	
		fout.open("outputE.txt");
		fout<<"sort"<<endl;
		for(int i=0;i<filenum;i++)
		{
			fout<<array4[i]<<endl;
		}
		fout.close();
		
		fout.open("time.txt",ios::app);
	    // selectionsort mergesort radixsort    qsort      sort 
		fout<<setw(10)<<filenum<<"     "<<setprecision(6)<<time[0]<<"     "<<setprecision(6)<<time[1]<<"     "<<setprecision(6)<<time[2]<<"     "<<setprecision(6)<<time[3]<<setprecision(6)<<"     "<<time[4]<<endl;
		fout.close();
		//mergesort(array,0,n-1);
		// radixsort(array,n);
		//qsort(array,n,sizeof(int),compare); 
		//sort(array,array+n);
		//printarray(array,n);
	
}
void selectionsort(int arr[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		 int min=i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
			{
				min=j;
			}
		}
		if(min!=i)
		{
			int temp=arr[min];
			arr[min]=arr[i];
			arr[i]=temp;
		} 
	}
}
void merge(int arr[], int p, int q, int r) {
  
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}
void mergesort(int arr[], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergesort(arr, l, m);
    mergesort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}
int getmax(int array[], int n)
{
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}
void countingsort(int array[], int size, int place)
{
  const int max = 10;
  int output[size];
  int count[max];

  for (int i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;

  // Calculate cumulative count
  for (int i = 1; i < max; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}
void radixsort(int array[], int size) 
{
  // Get maximum element
  int max = getmax(array, size);

  // Apply counting sort to sort elements based on place value.
  for (int place = 1; max / place > 0; place *= 10)
    countingsort(array, size, place);
}
int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
void printarray(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}

