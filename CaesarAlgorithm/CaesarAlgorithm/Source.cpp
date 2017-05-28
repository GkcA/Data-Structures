#include<iostream>
#include<cstdlib>
#include<string>
#include<conio.h>
#include<ctime>

using namespace std;

string Encrypt(string plainText,int key) {
	
	string cipherText=plainText;
	
	for (int i = 0;i < plainText.length();i++)
	{
		if ((char)65 <= plainText[i] && plainText[i] <= (char)90)
			cipherText[i] = (plainText[i]-65 + key)%26+65;
		else if ((char)97 <= plainText[i] && plainText[i] <= (char)122)
			cipherText[i] = (plainText[i]-97 + key )%26+97;
		else if (plainText[i] == ' ')
			cipherText[i] = plainText[i];
	}
	return cipherText;
}

string Decryption(string cipherText,int key)
{
	string plainText = cipherText;

	for (int i = 0;i < cipherText.length();i++)
	{
		if ((char)65 <= cipherText[i] && cipherText[i] <= (char)90)
		{
			if (plainText[i] = (cipherText[i] - 65 - key) % 26 < 0) 
				plainText[i] = (cipherText[i] - 65 - key) % 26 + 91;
			else
				plainText[i] = (cipherText[i] - 65 - key) % 26 + 65;
		}
		else if ((char)97 <= cipherText[i] && cipherText[i] <= (char)122)
		{
			if ((cipherText[i] - 97 - key) % 26< 0) 
				plainText[i] = (cipherText[i] - 97 - key) % 26+ 123;
			else
				plainText[i] = (cipherText[i] - 97 - key) % 26 + 97;
		}
		else if (cipherText[i] == ' ')
			plainText[i] = cipherText[i];
	}
	return plainText;
}

void main()
{

	string Text;
	srand((unsigned)time(NULL));
	int shiftKey = rand() % 13;
	char choice;
	cout << "Enter a Text: ";
	getline(cin, Text);
	system("cls");

	Text = Encrypt(Text, shiftKey);
	cout << "Cipher Text: " << Text<<endl;

	cout << "Want to see message : (Y/N)"<<endl;
	cin >> choice;

	if (toupper(choice) == 'Y') {
		system("cls");
		Text = Decryption(Text, shiftKey);
		cout << "Plain Text: " << Text << endl;
	}


	_getch();

}