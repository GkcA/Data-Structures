#include<iostream>
#include <cstdlib>
#include <string>
#include <ctype.h>
#include <cstring>
#include<conio.h>
using namespace std;

double *stack;
double r;
int top = -1;
double A = 10, B = 6, C = 4, D = 2, E = 5;

void push(char item) {
	
	if (item == 'A')
	{
		top++;
		stack[top] = A;
	}
	if (item == 'B')
	{
		top++;
		stack[top] = B;
	}
	else if (item == 'C')
	{
		top++;
		stack[top] =C;
	}
	else if (item == 'D')
	{
		top++;
		stack[top] = D;
	}
	else if (item == 'E')
	{
		top++;
		stack[top] = E;
	}

}
void push1(double item)
{
	top++;
	stack[top] = item;
}
double pop() {

	double item = stack[top];
	top--;
	return item;
}
void result(double o1,double o2,char opr)

{
	
		if (opr == '+')
		{
			r = o2 + o1;
		}
		else if (opr == '-')
		{
			r = o2 - o1;
		}
		else if (opr == '/')
		{
			r = o2 / o1;
		}
		else if (opr == '*')
		{
			r = o2 * o1;
		}
		push1(r);
}

int main()
{
	
	string sent;
	cout << "(A=10, B=6, C=4, D=2, E=5)\nifadeyi A,B,C,D,E cinsinden giriniz : ";
	getline(cin, sent);
	cout << endl;
	stack = new double[sent.length() + 1];
	
	int i = 0;
	while (i  < sent.length())
	{
		if (isalpha(sent[i]))
			push(sent[i]);
		else
		{
			double op1 = pop();
			double op2 = pop();
			result(op1,op2,sent[i]);
		}
		i++;
	}
	cout << r;
	_getch();
	return 0;

}