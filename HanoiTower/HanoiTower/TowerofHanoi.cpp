#include<iostream>
#include<cstdlib>
#include<cstring>
#include<ctype.h>
#include<conio.h>


using namespace std;
void hanoi(int n, char  s, char  i, char d) {
	if (n > 1)
	{
		hanoi(n - 1, s, d, i);
		cout << s << "-->" << d << endl;
		hanoi(n - 1, i, s, d);
	}
	else
		cout << s << "-->" << d << endl;
}

int main()
{
	for (int i =1 ;i <= 7;i++) {
		cout << i  << ".Step"<<endl<<"-------------"<<endl;
		hanoi(i, 's', 'i', 'd');
		cout << endl;
	}
	_getch();
	return 0;
}