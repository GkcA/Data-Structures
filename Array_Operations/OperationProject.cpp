#include<iostream>
#include<cstdlib>
#include<cstring>
#include<ctype.h>
#include<string>
#include<iomanip>

using namespace std;

int main()
{
	string str;
	int El_rm;
	int list[50];
	int count = 0;

	while (1)
	{
		//Menu
		cout << setw(20) << "MENU" << endl;
		cout << setw(27) << ">----------------<" << endl << endl;
		cout << "A--> Add Element List" << endl;
		cout << "R--> Remove Element of List " << endl;
		cout << "L--> List Elements Ordered Way" << endl;
		cout << "M--> Maximum Element of List" << endl;
		cout << "M--> Minimum Element of List" << endl;
		cout << "V--> Average of Elements at List" << endl;
		cout << "E--> Exit" << endl;

		cout << endl << "Your Choice: ";
		cin >> str;

		system("cls"); //ekran temizleme

		//Girilen karatere göre islemler

		if (str == "a" || str == "A")// adding 
		{
			if (count == 50)
			{
				cout << "Cannot add element due to list size!!";
			}
			else
			{
				cout << "Enter an element to add: ";
				cin >> list[count];
				count++;
			}
		}

		else if (str == "r" || str == "R")// removing
		{
			int cnt = count;
			int i;

			cout << "Enter element to remove: ";
			cin >> El_rm;

			//searching element ;
			while (El_rm != list[cnt]) {

				cnt--;

				if (cnt < 0)
				{
					cout << "ELEMENT COULDN'T BE FOUND!!" << endl << endl;
					system("pause");
					break;
				}
			} //end while;

			//changing list items 
			if (El_rm == list[cnt]) {
				for (i = cnt; i <= count - 1; i++)
				{
					list[i] = list[i + 1];

				}//end for

				list[i] = NULL;
				count--;

			}//end if
		}// end else if

		else if (str == "L" || str == "l") //listing elements ordered way;
		{

			cout << "Entered Elements of List: ";
			for (int i = 0; i < count; i++)
			{
				cout << list[i] << "\t";
			}

			cout << endl << endl;

			//Bubble Sort
			int swap;
			for (int i = 0; i < count - 1; i++) {
				for (int j = 0; j < count - 1; j++)
				{
					if (list[j] > list[j + 1])
					{
						swap = list[j];
						list[j] = list[j + 1];
						list[j + 1] = swap;
					}
				}
			}

			cout << "Ordered Elements of List: ";
			for (int i = 0; i < count; i++)
			{
				cout << list[i] << "\t";
			}

			cout << endl << endl;
			system("pause");
		}

		else if (str == "M" || str == "m") //finding max and min element of list
		{
			int choice;

			cout << "1--> Maximum Element" << endl;
			cout << "2--> Minimum Element" << endl;
			cout << "Your Choice: ";
			cin >> choice;

			system("cls");

			if (choice == 1) //choice for max
			{
				int max = list[0];

				for (int i = 0; i < count; i++) {

					if (list[i] > max)
						max = list[i];
				}

				cout << "Maximum Element is :" << max << endl << endl;
			}

			else if (choice == 2) //choice for min
			{
				int min = list[0];

				for (int i = 0; i < count; i++) {

					if (list[i] < min)
						min = list[i];
				}

				cout << "Minimum Element is :" << min << endl << endl;

			}

			else
				cout << "Incorrect choice!!" << endl << endl;


			system("pause");
		}

		else if (str == "v" || str == "V")// average of list
		{
			float sum = 0;

			for (int i = 0; i < count; i++)
			{
				sum = sum + (float)list[i];
			}

			cout << "Average is : " << sum / (float)count << endl << endl;
			system("pause");
		}

		else if (str == "E" || str == "e")// for exit
		{
			exit(0);
		}

		system("cls");//cleaning screen;
	}
	return 0;
}
