#include<iostream>
#include<cstdlib>
#include<cstring>
#include<conio.h>
#include<iomanip>
#include<string>

using namespace std;

typedef struct Node {

	int data;
	struct Node *next;
};

Node *top = NULL;

void pop() { // deleting item at the top

	if (top == NULL)  //checks whether item is empty or not
		cout << "Stack is Empty ...";

	else {
		Node* temp = top; //temp node holds info of top list
		top = top->next; //last element is removed
		cout << "Item at the top is : " <<temp->data << "\nNow is popping..."; //prints item is popped.
		delete temp; //deletes temp
	}
	_getch();
}
void push() {  //adding item to stack

	int pu_item;  //declaration of item we will add to stack
	
	cout << "Enter an item to Add : ";
	cin >> pu_item;  //reads the item user entered

	Node *Newnode=new Node; //new node is created
	
	Newnode->data = pu_item; //adding item to new node data
	if (top == NULL) //if stack is empty then new node's next shows null
		Newnode->next = NULL;
	else 
		Newnode->next = top; //else shows top node

	top = Newnode; //assaigning new node to top list
}

void list()
{
	if (top == NULL) // checks stack is empty
		cout << "Stack is Empty...";

	else {
		Node* tmp = top; // new temp node is created and holding data of top list

		while (tmp->next != NULL){ //until end of the list
			cout << "| " << setw(6) << right << tmp->data << " |" << endl;
			tmp = tmp->next; //updating tmp
		} 
		cout << "| " << setw(6) << right << tmp->data << " |" << endl;//printing value at the bottom of stack
	}

	_getch(); //to stop console until press any key so we can see results
	system("cls");
}

void count() { //prints value of (top+1), which is equal number of item in stack

	int cnt = 1;
	Node * tmp = top;

	if (top == NULL) //checks whether stack is empty or not
		cout << "Stack is empty...";
	else
	{
		while (tmp->next != NULL)//until end of the linked list we increment counter 
		{
			tmp = tmp->next;
			cnt++; 
		}
		cout << "Number of item in Stack is : " << cnt;
	}

	_getch();//to stop console until press any key so we can see results
}

int main()
{
	char ch; //choice from menu

	while (1)
	{
		cout << " MENU" << endl;
		cout << ">----<" << endl << endl;
		cout << "A--> PUSH Item to Stack " << endl;
		cout << "D--> POP Item to Stack " << endl;
		cout << "L--> List Item of Stack " << endl;
		cout << "C--> Count Number of Item in Queue " << endl;
		cout << "E--> Exit" << endl;

		cout << endl << "Your Choice: ";
		cin >> ch;

		system("cls"); //cleans console

		if (toupper(ch) == 'A') //for adding item
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
	return 0;
}