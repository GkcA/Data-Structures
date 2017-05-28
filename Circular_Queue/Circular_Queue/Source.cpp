#include<iostream>
#include<cstdlib>
#include<cstring>
#include<ctype.h>
#include<conio.h>


using namespace std;

int *Queue = NULL;
int Rear = -1, Front = -1, q_size;

void dequeue() { // deleting first item of queue

	if (Front == -1) //checks queue is empty
		cout << "Queue is empty.";
	else
	{
		cout<<"Item at first place: "<< Queue[Front]<<" is removed"<<endl;//prints item which is deleted
		Queue[Front] =NULL;//assing null in place of deleted item
		if (Front == Rear) //checks list is empty 
		{
			//both return initial position
			Front = -1; 
			Rear = -1;
		}
		else if (Front == q_size - 1) //Front shows last place in queue 
			Front = 0; //Now shows first place
		else
			Front++; //increment adding 1
	}
	_getch();//to stop console until press any key so we can see results

}
void enqueue() { //adding item to rear of queue

	int num;

	if ((Front == 0 && Rear == q_size - 1) || (Front == Rear + 1)) //checks queue is full
	{
		cout << "Queue is Full." << endl;
		_getch(); //to stop console until press any key so we can see results 
	}
	else
	{
		cout << "Enter Item to add: ";
		cin >> num;

		if (Rear == -1) //if queue is empty 
		{
			//both indicate 0th element of queue
			Rear = 0; 
			Front = 0;
		}
		else if (Rear == q_size - 1) //if Rear reaches end of queue 
			Rear = 0; //now it indicates 0th element of queue
		else
			Rear++; //increment Rear adding by 1

		Queue[Rear] = num;	//assigns new number to first free place
	}
}
void list()
{
	int i;
	
		if (Front == -1) // control list is empty?
			cout << "Queue is empty.\n";
		else
		{
			i = Front; //assaing Front to i to access first item
			int cnt=0; //counter for counting number of item of in queue
			while (1)
			{	

				 if (Front <= Rear) { 
					cout << (cnt+1) << ". " << Queue[i] << "\n";
					i++; //increment i adding 1
					cnt++;	//increment counter adding 1
				}
				else //checks Front> Rear
				{
					cout << (cnt+1) << ". " << Queue[i] << "\n";
					/* we increment i taking mod of size of queue in order to reach elements if Front indicates last item etc.*/
					i = (i+1) % q_size; 
					cnt++;
				}

				if ((Rear - Front + q_size) % q_size==cnt-1) //checks number of elements in queue is equal our counter to stop loop
					break;
			
			}
		}
	
	_getch(); //to stop console until press any key so we can see results
}
void count() {

	int numofitem = 1+((Rear-Front+q_size)%q_size); //assaignin number of item in queue
	
	if (Front == -1)
		cout << "Queue is empty";
	else
		cout << "Number of item in Queue is " << numofitem;
	
	_getch();//to stop console until press any key so we can see results
}
int main()
{

	char ch;
	cout << "Please Enter Size of Queue : ";
	cin >> q_size;
	Queue = new int[q_size]; //creating dynamically allocated array with given size
	system("cls"); // cleans console

	while (1)
	{
		cout << " MENU" << endl;
		cout << ">----<" << endl << endl;
		cout << "A-->Add Item to Queue " << endl;
		cout << "D-->Delete Item to Queue " << endl;
		cout << "L-->List Item of Queue " << endl;
		cout << "C-->Count Number of Item in Queue " << endl;
		cout << "E--> Exit" << endl;

		cout << endl << "Your Choice: ";
		cin >> ch;

		system("cls"); //cleans console

		if (toupper(ch) == 'A') //for adding item
		{
			enqueue();
		}

		else if (toupper(ch) == 'D') //for deleting item
		{
			dequeue();
		}
		else if (toupper(ch) == 'L') // for listing
		{
			list();
		}
		else if (toupper(ch) == 'C') // for counting num. of item
		{
			count();
		}

		else if (toupper(ch) == 'E')// to exit
		{
			exit(0);
		}

		system("cls");//cleans console;
	}
	return 0;
}