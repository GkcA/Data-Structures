#include<iostream>
#include<cstdlib>
#include<cstring>
#include<conio.h>
#include<iomanip>
#include<string>

using namespace std;

typedef struct binary_tree_nodes { //structure of bst
	int value;
	binary_tree_nodes *left;
	binary_tree_nodes *right;
}Node;

Node* root = NULL; //initially points null
Node*temp1= NULL;

int flag = 1;//Checks whether node is deleted or not
int flag2 = 1;//Checks whether node is empty or not used in list function
int flag3 = 0;//Checks where node is added
int depth = 0;//finds depth;

Node* insertion(Node *R, int num) {  //adding node to bst

	Node *newNode = new Node;//creating new node
	//assaigning value to new node.
	newNode->value = num;
	newNode->left = NULL;
	newNode->right = NULL;

	if (R != NULL) { //checks whether r is null or not.
		if (num < R->value) //number is lower than value of node.
		{
			flag3 = 1;
			temp1 = R;//holds information of parent
			depth++;//increasing depth
			R->left = insertion(R->left, num); //go to left of bst.
		}
		else if (num >= R->value)
		{
			flag3 = 2;
			temp1 = R;//holds information of parent
			depth++;//increasing depth
			R->right = insertion(R->right, num); //go to right of bst.
		}
	}
	else {
		
			R = newNode; //assaigining new node to bst.
			if (flag3 == 1) 
				cout <<endl<<"Node was added as Left child of " << temp1->value<<endl<<"Depth is : "<<depth;
			else if(flag3==2)
				cout <<endl<<"Node was added as Right child of "<<temp1->value<<endl<<"Depth is : " << depth;
			else
				cout <<endl<<"Node was added to Root"<<endl<< "Depth is : " << depth;
			flag3 = 0;//updating values to initial
			depth = 0;//updating values to initial
	}
	return R; //returns bst.
}

Node* list(Node*r, int choice) //listing
{
	if (choice == 1) { // to list increasing order
		if (r != NULL) {
			flag2 = 0;
			list(r->left, choice); // go left of bst
			cout << r->value << " "; // print value
			list(r->right, choice); //go right of bst
		}
	}
	else { // to list decreasing order

		if (r != NULL) {
			flag2 = 0;
			list(r->right, choice); //go right of bst
			cout << r->value << " "; //print value
			list(r->left, choice); // go left of bst
		}
	}
	if (flag2 == 1) { // checks whether tree is empty or not
		system("cls");
		cout << "Tree does not exist...";
	}
	return r; // return tree.
}

bool Search(Node *r, int num) { //searching

	if (r == NULL) { // if tree is empty
		cout << "Node couldn't be found!!";
		return false;
	}
	else if (r->value == num) { //found node
		cout << "Node is found!!";
		return true;
	}
	else if (num < r->value) //go to left if num is lower than value of node
		return Search(r->left, num);
	else  //go to right if num igreater than value of node
		return Search(r->right, num);
}

Node* FindMin(Node* r)//finding minumum nodes
{
	while (r->left != NULL) r = r->left; //go to left of tree.
	return r; // returns node;
}

Node * deletion(Node*r, int num) { //deleting nodes

	if (r == NULL) { //if tree does not exist.
		cout << "Node does not exist!!";
		flag = 0;
		return r;
	}
	//Searching node is to be deleted;
	else if (num < r->value)
		r->left = deletion(r->left, num);
	else if (num > r->value)
		r->right = deletion(r->right, num);
	//find the node , now going to be deleted
	else {

		//case1 : No child
		if (r->left == NULL && r->right == NULL) {
			delete r;
			r = NULL;
			flag = 0;
			return r;
		}
		//case2 : One child
		else if (r->left == NULL) { //deleting right child
			Node*temp = r;
			r = r->right;
			delete temp;
			flag = 1;
		}
		else if (r->right == NULL) { //deleting left child
			Node*temp = r;
			r = r->left;
			delete temp;
			flag = 1;
		}
		//case3 : Two child
		else {
			Node*temp = FindMin(r->right);// finds minumum of right side
			r->value = temp->value; //assigining minumum to node wanted to be deleted.
			r->right = deletion(r->right, temp->value); //deletion right side
			flag = 2;
		}
	}
	return r; //returns node
}

Node* count(Node*r, int &cnt)
{
	if (r != NULL) { //counting node number
		count(r->left, cnt);
		cnt++;
		count(r->right, cnt);
	}
	return r;//returns node.
}

int main()
{
	char ch; //choice from menu

			 //menu
	while (1)
	{
		cout << " MENU" << endl;
		cout << ">----<" << endl << endl;
		cout << "A--> Insert Node to Tree " << endl;
		cout << "D--> Delete Node from Tree " << endl;
		cout << "L--> List Nodes" << endl;
		cout << "S--> Search Node in Tree " << endl;
		cout << "C--> Count Nodes in Tree " << endl;
		cout << "E--> Exit" << endl;

		cout << endl << "Your Choice: ";
		cin >> ch;

		system("cls"); //cleans console

		if (toupper(ch) == 'A') //for adding item
		{
			int num;
			cout << "Enter Number to Add : ";
			cin >> num;
			root = insertion(root, num);//function is calling
			_getch();
		}
		else if (toupper(ch) == 'D') //for deleting item
		{
			int num;
			cout << "Enter Number to Delete : ";
			cin >> num;
			root = deletion(root, num); //function is calling
			if (flag == 1)
				cout << "Node has one child is deleted.";
			else if(flag==2)
				cout << "Node has two child is deleted.";
			else if(flag==0)
				cout << "Leaf is deleted.";
			_getch();
			system("cls");
		}
		else if (toupper(ch) == 'L') // for listing
		{
			int ch;
			do { //checks our input and write message 
				cout << "1--> increasing order " << endl;
				cout << "2--> decreasing order " << endl;
				cout << "Choice : ";
				cin >> ch;
				if (ch >= 3 || ch <= 0)
				{
					system("cls");
					cout << "Wrong Choice Try Again...";
					_getch();
					system("cls");
				}

			} while (ch >= 3 || ch <= 0);
			flag2 = 1;
			root = list(root, ch);//function is calling
			_getch();
		}
		else if (toupper(ch) == 'S') // for searching element.
		{
			int num;
			cout << "Item want to Search :";
			cin >> num;
			Search(root, num); //function is calling
			_getch();
		}
		else if (toupper(ch) == 'C') // for counting nodes.
		{
			int cnt = 0;
			root = count(root, cnt);
			cout << "Number of nodes : " << cnt;
			_getch();
		}
		else if (toupper(ch) == 'E')// to exit
		{
			exit(0);
		}
		else { //for error mesasage according to wrong choice from menu
			cout << "Invalid choice from the menu";
			_getch();//to see message until we press any key
		}

		system("cls");//cleans console;
	}
	return 0;
}