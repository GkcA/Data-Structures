//including libraries
#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include<time.h>
using namespace std;

#define sizeOne 1000 //size k
#define sizeTwo 10000 //size 10k
#define sizeThree 100000 //size 100k
#define indexMin 0 //used in quick sort algorithm to identify firs element.
#define width 33 //used in printing title in title function.

/*function creates random array with given size*/
int* CreateArray(int *Array, int size) {
	srand((unsigned)time(NULL));//to get different random number every compilation
	Array= new int[size];//creating new array

	//loop for filling array with random number
	for (int i = 0;i < size;i++) {
		Array[i] = rand() % RAND_MAX;
	}
	return Array;//returns random array
}

/*Bubble sort Algorithm */
/* Worst case : O(n^2)
   Average case : Θ(n^2)
   Best case : Ω(n) */
void BubbleSort(int arrayToSort[],int size) {

	int temp;
	//loop for swapping process
	for (int i = 1;i <= size - 1;i++)
	{
		for (int j = 0;j <= size - i - 1;j++)
		{
			//swapping
			if (arrayToSort[j] > arrayToSort[j + 1])
			{
				temp = arrayToSort[j];
				arrayToSort[j] = arrayToSort[j + 1];
				arrayToSort[j + 1] = temp;
			}
		}
	}
}

//Insertion sort Algorithm 
/* Worst case : O(n^2)
   Average case : Θ(n^2)
   Best case : Ω(n) */
void InsertionSort(int arrayToSort[], int size) {
	
	int j, temp;
	//loops for sorting
	for (int i = 1; i < size; i++) {
		j = i;
		//swapping
		while (j > 0 && arrayToSort[j - 1] > arrayToSort[j]) {
			temp = arrayToSort[j];
			arrayToSort[j] = arrayToSort[j - 1];
			arrayToSort[j - 1] = temp;
			j--;
		}
	}
}

//Selection Sort algorithm 
/* Worst case : O(n^2)
   Average case : Θ(n^2)
   Best case : Ω(n^2) */
void SelectionSort(int arrayToSort[], int size) {
	
	int minIndex, temp;
	//loop for sorting process
	for (int i = 0; i < size - 1; i++) {
		minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (arrayToSort[j] < arrayToSort[minIndex])
				minIndex = j;
		}
		//swapping
		if (minIndex != i) {
			temp = arrayToSort[i];
			arrayToSort[i] = arrayToSort[minIndex];
			arrayToSort[minIndex] = temp;
		}
	}
}

//Quick sort algorithm uses divide-and-conquer methods
/*Worst case : O(n^2)
  Average case : Θ(n log(n))
  Best case : Ω(n log(n))*/
void QuickSort(int arrayToSort[], int left, int right) {

	int i = left, j = right; //declaration of i and j
	int temp;//declaration of temp
	int pivot = arrayToSort[(left + right) / 2];//finding middle index value

	/* partition */
	while (i <= j) {
		//looking for index lower than pivot
		while (arrayToSort[i] < pivot)
			i++;
		while (arrayToSort[j] > pivot)
			j--;
		if (i <= j) {//swapping 
			temp = arrayToSort[i];
			arrayToSort[i] = arrayToSort[j];
			arrayToSort[j] = temp;
			i++;
			j--;
		}
	}

	/* recursion */
	if (left < j)
		QuickSort(arrayToSort, left, j);
	if (i < right)
		QuickSort(arrayToSort, i, right);
}

//function calculates duration time
double Duration(clock_t end, clock_t start)
{
	return (double)(end - start) / CLOCKS_PER_SEC;
}

//function copies initial unsorted array
int*CopyArray(int *unsortedArray,int *tmp, int size)
{
	tmp = new int[size];//allocating memory for array with given size
	
	//loop for copying given array into tmp
	for(int i =0;i<size;i++)
	  tmp[i] = unsortedArray[i];
	return tmp;//returns tmp array
}

//function gets initial unsorted array
int*UnSortedBack(int *sortedArray,int *tmp ,int size)
{
	//loop for copying items
	for (int i = 0;i<size;i++)
	  sortedArray[i]=tmp[i];
	return sortedArray;//returns sortedArray
}

//function calculates time for each sorting algorithm and prints results on console
int* CalculateTime(int arrayToSort[],int tmp[] ,int size)
{
	clock_t endTime,startTime;//declaration of start time and end time

	startTime = clock();//getting the processor time consumed by the program.
	BubbleSort(arrayToSort, size);//bubble sort algorithm is called
	endTime = clock();//getting the processor time consumed by the program.
	cout<<"\nDuration of Bubblesort : "<<Duration(endTime,startTime)<<endl;//prints result

	arrayToSort=UnSortedBack(arrayToSort,tmp, size);//calling function to bring back unsorted array
	startTime = clock();//getting the processor time consumed by the program.
	SelectionSort(arrayToSort, size);//selection sort algorithm is called
	endTime = clock();//getting the processor time consumed by the program.
	cout << "Duration of Selectionsort : " << Duration(endTime, startTime)<<endl;//prints result
	
	arrayToSort=UnSortedBack(arrayToSort,tmp, size);
	startTime = clock();//getting the processor time consumed by the program.
	InsertionSort(arrayToSort, size);//insertion sort algorithm is called
	endTime = clock();//getting the processor time consumed by the program.
	cout << "Duration of Insertionsort : " << Duration(endTime, startTime)<<endl;//prints result
	
	arrayToSort=UnSortedBack(arrayToSort,tmp, size);
	startTime = clock();//getting the processor time consumed by the program.
	QuickSort(arrayToSort, indexMin, size - 1);//quick sort algorithm is called
	endTime = clock();//getting the processor time consumed by the program.
	cout << "Duration of Quicksort : " << Duration(endTime, startTime)<<endl<<endl;//prints result

	return arrayToSort;//returns sorted array
}


int i = 0;//declaration of i
//function prints title 
void Title(int size)
{
	cout <<"*"<<setfill('-')<<setw(width+i)<<"*"<<endl;
	cout << "| Results of Array has " << size << " Item |" << endl;
	cout << "*" << setfill('-') << setw(width + i) << "*" << endl;
	i ++;//increments i
}

void main()
{
	int *list=NULL;//declaration of pointer is going to be array
	int *temp = NULL;//declaration of pointer is going to be array holds copy array

	//function calls for calculating sorting time for 1000 items
	Title(sizeOne);
	list = CreateArray(list, sizeOne);
	temp=CopyArray(list,temp, sizeOne);
	list =CalculateTime(list,temp,sizeOne);

	//function calls for calculating sorting time for 10000 items
	Title(sizeTwo);
	list = CreateArray(list, sizeTwo);
	temp=CopyArray(list, temp, sizeTwo);
	list =CalculateTime(list,temp,sizeTwo);

	//function calls for calculating sorting time for 100000 items
	Title(sizeThree);
	list = CreateArray(list, sizeThree);
	temp=CopyArray(list,temp, sizeThree);
	list=CalculateTime(list,temp,sizeThree);

	_getch();//press any key to continue
}