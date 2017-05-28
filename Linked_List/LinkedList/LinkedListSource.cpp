#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<string>
#include<ctype.h>

using namespace std;

typedef struct list_element {
	int value;
	struct list_element *pprev;
	struct list_element *pnext;
}Element;

Element *head = NULL;
Element *last = NULL;

Element *add_element(Element *p);
Element* delete_element(Element *p);
void list_element(Element *r);
int count_element(Element *r);

int main()
{
	char str;
	while (1)
	{
		cout << setw(20) << "MENU" << endl << endl;
		cout << setw(27) << "A--> ADDING ELEMENT" << endl;
		cout << setw(30) << "D--> DELETING ELEMENT " << endl;
		cout << setw(29) << "L--> LISTING ELEMENT " << endl;
		cout << setw(41) << "C--> COUNTING NUMBER OF ELEMENTS " << endl;
		cout << setw(17) << "E--> Exit" << endl;
		cout << setw(21) << endl << "Your Choice: ";
		cin >> str;
		system("cls"); //ekran temizleme

		if ('A' == toupper(str))			//for adding	
			{ head = add_element(head); } 
		else if (toupper(str) == 'L')		// for listing	
			{ list_element(head); }  
		else if (toupper(str) == 'C')	    //counting
		{
			cout << "Number of Element at List :" << count_element(head) << endl;
			system("pause");
		}
		else if ('D' == toupper(str))		// for deleting
		{
			head = delete_element(head);
			system("pause");
		}
		else if ('E' == toupper(str)) { exit(0); } //for exit

		system("cls");  //cleaning screen;
	}//end while

	system("pause");
	return 0;
}

Element * add_element(Element *p) {

	int x;
	cout << "Please Enter Item: ";
	cin >> x;
	cout << endl;

	if (p == NULL)//if list is empty add new item
	{
		p = new Element;
		p->pnext = NULL;
		p->pprev = NULL;
		p->value = x;
		return p;
	}

	Element *Iter = p;
	while (Iter->pnext != NULL)
	{
		Iter = Iter->pnext;
	}
	Element *temp = new Element;
	temp->pnext = Iter->pnext;
	Iter->pnext = temp;
	temp->pprev = Iter;
	temp->value = x;
	return p;
}
Element* delete_element(Element *p) {

	Element *temp;
	Element *iter = p;
	int x;

	cout << "Enter Item Want to Delete : ";
	cin >> x;

	if (iter == NULL) {
		cout << endl << "Oops you cannot delete item beacuse List is empty!!" << endl;
		return p;
	}
	if (p->value == x)
	{
		temp = p;
		if (p->pnext == NULL && p->pprev == NULL) {
			p = NULL;

		}
		else {
			p = p->pnext;
			p->pprev = NULL;
		}
		cout << "Selected item was deleted!!" << endl;
		delete (temp);
		return p;

	}
	while (iter->pnext != NULL && iter->pnext->value != x)
		iter = iter->pnext;

	if (iter->pnext == NULL) {
		cout << "Item does not exist at list!!!" << endl;
		return p;
	}
	temp = iter->pnext;
	iter->pnext = iter->pnext->pnext;
	delete (temp);
	if (iter->pnext != NULL)
		iter->pnext->pprev = iter;
	cout << "Selected item was deleted!!" << endl;
	return p;
}
void list_element(Element *r) {

	Element *Iter = r;
	if (Iter != NULL)
	{
		while (Iter->pnext != NULL) //sonuncu elemaný bulma
		{
			Iter = Iter->pnext;
		}
		last = Iter; //sonuncu elemaný last degerýný  atama
	}

	if (r == NULL) {
		cout << "List is empty !!" << endl;
		system("pause");
	}
	else {
		cout << "Entered Order of List : ";
		while (r)
		{
			cout << r->value << "\t";
			r = r->pnext;
		}
		cout << endl << "Reversed Order of List : ";
		while (Iter) //tersten yazma
		{
			cout << Iter->value << "\t";
			Iter = Iter->pprev;
		}
		cout << endl;
		system("pause");
	}
}
int count_element(Element *r) {

	int count = 0;
	Element *Iter = r;
	if (Iter != NULL) {
		while (Iter->pnext != NULL) //sonuncu elemaný bulma
		{
			Iter = Iter->pnext;
			count++;
		}
		return count + 1;
	}
	return count;
}