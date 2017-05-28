#include<iostream>
#include<cstdlib>
#include<cstring>
#include<conio.h>
#include<iomanip>
#include<string>

using namespace std;

int *Stack = NULL; //this variable will be our array
int s_size; //size of stack
int top = -1; //top is initialized -1

void pop() { // deleting item at the top

	if (top == -1)  //checks whether item is empty or not
		cout << "Stack is Empty ...";

	else {
		cout << "Item at the top is : " << Stack[top] << "\nNow is popping..."; //prints item is popped.
		Stack[top] = NULL; // value of that item now is null
		top--; //item of the top is changed
	}
	_getch();
}
void push() {  //adding item to stack
	
	int pu_item;  //declaration of item we will add to stack 

	if (top == s_size - 1) {  //checks whether stack is full or not
		cout << "Stack Overflow ...";
		_getch();
	}
	else {
		cout << "Enter an item to Add : ";
		cin >> pu_item;  //reads the item user entered
		Stack[++top] =pu_item;  // item is adding to stack
	}
}

void list()
{
	if (top == -1)
		cout << "Stack is Empty...";

	else {
		
		for (int i = top; i >= 0;i--)
		{
			cout<<"| "<<setw(6)<<right<<Stack[i]<<" |" << endl;
		}
	}

	_getch(); //to stop console until press any key so we can see results
	system("cls");
}

void count() { //prints value of (top+1), which is equal number of item in stack
	
	if (top == -1) //checks whether stack is empty or not
		cout << "Stack is empty...";
	else
		cout << "Number of item in Stack is : " << top+1;

	_getch();//to stop console until press any key so we can see results
}

void pcnt()
{
	int num, flag = 0, cnt=0;
	cout << "search pop : " ;
	cin >> num;

	for (int i = top;i>=0;i--) {
		if (Stack[i] == num)
		{
			flag = 1;
			break;
		}
		cnt++;
	}
	if (flag == 1) {
		cout << "pop times :" << (cnt+1);
		_getch();
	}

}

int main()
{
	char ch; //choice from menu
	
	//loop continues until valid size is entered
	do {
		cout << "Please Enter Size of Stack : ";
		cin >> s_size;

		if (s_size < 0) {
			cout << "Invalid size...";
			_getch();
		}
		else
			Stack = new int[s_size]; //creating dynamically allocated array with given size

		system("cls"); // cleans console

	} while (s_size < 0);

	while (1)
	{
			cout << " MENU" << endl;
			cout << ">----<" << endl << endl;
			cout << "A--> PUSH Item to Stack " << endl;
			cout << "D--> POP Item to Stack " << endl;
			cout << "L--> List Item of Stack " << endl;
			cout << "C--> Count Number of Item in Queue " << endl;
			cout << "T--> Pop times " << endl;
			cout << "E--> Exit" << endl;

			cout << endl << "Your Choice: ";
			cin >> ch;

			system("cls"); //cleans console

		if (toupper(ch) =='A') //for adding item
		{
			push();
		}
		else if (toupper(ch) == 'D') //for deleting item
		{
			pop();
			system("cls");
		}
		else if (toupper(ch) == 'L') // for listing
		{
			list();
		}
		else if (toupper(ch) == 'C') // for counting num. of item
		{
			count();
		}
		else if (toupper(ch) == 'T') // for counting num. of item
		{
			pcnt();
		}
		else if (toupper(ch) == 'E')// to exit
		{
			exit(0);
		}
		else {
			cout << "Invalid choice from the menu";
			_getch();
		}
		
		system("cls");//cleans console;
	}
	delete[] Stack;
	return 0;
}