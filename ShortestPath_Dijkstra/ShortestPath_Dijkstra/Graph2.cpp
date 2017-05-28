#include<iostream>
#include<cstdlib>
#include<cstring>
#include<conio.h>
#include<iomanip>
#include<time.h>

#define INFINITY 99999
using namespace std;

char ch = 65;

//function for allocating memory for matrix.
int **Allocate_Adjacency(int **Matrix, int nodeNum)
{
	//creating rows for matrix
	Matrix = new int*[nodeNum];
	//loop for creating columns .
	for (int i = 0;i < nodeNum;i++)
		Matrix[i] = new int[nodeNum];
	return Matrix;//returns matrix
}

//function for creating random adjacency matrix.
int ** MakeRandom_Adjacency(int **Matrix, int nodeNum)
{
	for (int i = 0;i <nodeNum;i++)//loop for creating lower triangle
	{
		for (int j = 0; j<nodeNum; j++)
		{
			if (i == j)//node itself,no path
				Matrix[i][j] = 0;
			else
				Matrix[i][j] = 0 + rand() % (9 - 0 + 1);//given random number between 0 and 9.
		}
	}
	return Matrix;//returns matrix
}

//function for printing matrix
void Print_Adjacency(int**Matrix, int nodeNum)
{
	system("cls");//cleans console

				  //title
	cout << "+----------------------+" << endl;
	cout << "| Distance Information |" << endl;
	cout << "+----------------------+" << endl;

	cout << "  ";
	for (char i = 'A';i < nodeNum+65;i++)//printing order for column
		cout << setw(4) <<i;
	cout << endl << "  ";
	for (int i = 0; i < nodeNum; i++)//printing character
		cout << setw(4) << "_";
	cout << endl;

	//printing matrix
	for (int i = 0;i <nodeNum;i++)
	{
		cout << (char)(ch+i) << "|";
		for (int j = 0; j < nodeNum; j++)
		{
			cout << setw(4) << Matrix[i][j];
		}
		cout << endl;
	}
}

//function to find short path
void Find_Information(int ** Matrix, int nodeNum)
{
	int node1, node2;
	char Node1, Node2;
	do { //getting nodes and checks if them correct
		Print_Adjacency(Matrix, nodeNum);//calling function to print adjacency matrix

		//getting first node and second.
		cout << "Choose Initial Node : ";
		cin >> Node1;
		cout << "Choose End Node : ";
		cin >> Node2;

		//lower letter which is proper character becomes upper letter.
		Node1=toupper(Node1);
		Node2=toupper(Node2);

		//making integer value taking mod 65
		node1 = (int)Node1%65;
		node2 = (int)Node2%65;

		if (node1<0 || node1>nodeNum || node2<0 || node2>nodeNum) {//checks whether nodes are proper or not.
			cout << "Wrong Choice";
			_getch();//press any key to continue
			system("cls");//cleans console
		}
		else if (node1 == node2) {//No path for same nodes.
			cout << "No Path!!";
			_getch();//press any key to continue
			system("cls");//cleans console
		}
	} while (node1 == node2 || node1<0 || node1>nodeNum || node2<0 || node2>nodeNum);

	int *cost = new int[nodeNum];//creating cost array holds cost value
	int *visited = new int[nodeNum];//creating visited array holds visited nodes
	int *pred = new int[nodeNum];//creating pred array holds previous nodes
	int count = 0;//counter
	int nextNode;//holds index of next node
	int *NormalOutput = new int[nodeNum];//creating NormalOutput array to print path correct order

	int b = 0;
	 //loop for initializing variables.
	do {
		for (int i = 0;i < nodeNum;i++)
		{
			if (Matrix[node1][i] == 0)//if zero
				cost[i] = INFINITY;//cost of that point is infinity
			else
				cost[i] = Matrix[node1][i];//assaiging cost value of initial node.

			visited[i] = 0;//assaiginig zero to all index of visited array.
			pred[i] = node1;//updating previous to initial node.
		}

		visited[node1] = 1;//initial node was visited.

		while (count < nodeNum - 1) {//loop for finding shortest path.

			int minCost = INFINITY;//declaration of minCost and initialing it to infinity
			for (int i = 0;i < nodeNum;i++)//loop for finding lower cost of each node.
			{
				if (!visited[i] && cost[i] < minCost)//checks unvisited and path has lowest cost exist.
				{
					minCost = cost[i];//updating minCost.
					nextNode = i; //updating index of nextNode.
				}
			}

			visited[nextNode] = 1;//next node is visited
								  //loop for checking if a better path exists through nextnode           
			for (int i = 0;i < nodeNum;i++)
			{
				//checks better path exist.
				if (!visited[i] && Matrix[nextNode][i] != 0 && minCost + Matrix[nextNode][i] < cost[i])
				{
					cost[i] = minCost + Matrix[nextNode][i];//cost is updated.
					pred[i] = nextNode;//previous node is updated.
				}
			}
			count++;//count is incremented.
		}

		//now path is printing with cost
		cout << "\n\nPATH FROM " << (char)(node1 + ch) << " TO " << (char)(node2 + ch) << endl;

		int k = 0;//declaration of k and it is initialized to zero;
		int j = node2;//declaration of j and initilized to end node
		NormalOutput[k++] = node2;
		do //loop for path is assaigning to normalOutput array
		{
			j = pred[j];//updating j to previous node
			NormalOutput[k++] = j;//path is added to array
		} while (j != node1);

		for (int i = k - 1; i >= 0; i--)//loop for printing path
		{
			cout << (char)(NormalOutput[i] + ch);
			if (i != 0)
				cout << " -> ";
		}
		cout << endl;
		for (int i = k - 1; i > 0; i--)//loop for printing information
		{
			cout << "DISTANCE BETWEEN " << (char)(NormalOutput[i] + ch) << "-" << (char)(NormalOutput[i - 1] + ch) << " = " << Matrix[NormalOutput[i]][NormalOutput[i - 1]] << endl;
		}
		cout << "TOTAL COST :  " << cost[node2];//printing cost.
		
		int temp = node1;
		node1 = node2;
		node2 = temp;
		b++;
		count = 0;
	} while (b < 2);
}

int main()
{
	srand((unsigned)time(NULL));//to get different random number every 
	int **adjacency = NULL;//declaration of adjacency matrix
	int nodeNum = 1;//declaration and initialization of nodeNum

	do //loop for taking proper node number.
	{
		cout << "Enter Node Number(Max 10) --> ";
		cin >> nodeNum;
		if (cin.fail() || nodeNum > 10 || nodeNum <= 0)//checks nodeNum is proper or not
		{
			cout << "Invalid Node Number\nNode Number must be between 0 and 10!!";//prints error message
			cin.clear();//clear cin
			cin.ignore();//ignores character.
			_getch();//press any key to continue
			system("cls");//cleans console.
		}
	} while (nodeNum > 10 || nodeNum <= 0);

	adjacency = Allocate_Adjacency(adjacency, nodeNum);//allocating memory for matrix
	adjacency = MakeRandom_Adjacency(adjacency, nodeNum);//calling function to fill matrix with random num.
	Find_Information(adjacency, nodeNum);//calling function to find shortest path.

	_getch();//press any key to continue
}