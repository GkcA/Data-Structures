//including libraries
#include"graphics.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;//to used write cout etc without prefix of std

#define ScreenX 900//width of graphic window
#define ScreenY 450//height of graphic window 

#define x_AxisMin 100//min x axis for shifted graph
#define x_AxisMax 700//max x axis for shifted graph

#define y_AxisMin 100//min y axis for shifted graph
#define y_AxisMax 300//max y axis for shifted graph

int main()
{
	fstream coordinateFile;//declaration of coordinateFile
	string filename;//declaration of filename
	string getCoordinate;//declaration of getCoordinate
	double Xcord;//declaration of x coordinate received from file
	double Ycord;//declaration of y coordinate received from file
	int cnt = 0;//counter for counting number of points read
	char terminate;//character to terminate program
	char* cord;
	
	//loop to program go on until user terminate input
	do {
		//getting name of file 
		cout << "Enter a file name (Lb9.txt): " << endl;
		getline(cin, filename);

		coordinateFile.open(filename, ios::in);//opening file input mode

		initwindow(ScreenX, ScreenY, "");//creating window for graphics

		//checks if file is available or not
		if (!coordinateFile)
		{
			cout << "File couldn't be found !!" << endl;//prints not found
			system("pause");//pause to console until press any key
			return 0;//terminates program
		}
		//drawing line for both axis
		line(x_AxisMin, y_AxisMin, x_AxisMin, y_AxisMax);
		line(x_AxisMin, y_AxisMax, x_AxisMax, y_AxisMax);

		coordinateFile >> getCoordinate;//reading x coordinate
	
		while (!coordinateFile.eof())//loop continue until it reaches end of file
		{
			Xcord = atof(getCoordinate.c_str());//converting string to double and assaing it to Xcord
			if (cnt == 193 || cnt == 55 || cnt == 435 || cnt == 314 || cnt == 500) {
				cord = new char[getCoordinate.length()];
				strcpy_s(cord, getCoordinate.length() + 1, getCoordinate.c_str());
				settextstyle(2, 0,300);
				outtextxy(Xcord + x_AxisMin, y_AxisMax + 10, cord);
			}
			coordinateFile >> getCoordinate;//reading y coordinate
			Ycord = atof(getCoordinate.c_str());//converting string to double and assaing it to Ycord
			putpixel((Xcord + x_AxisMin), (y_AxisMax- Ycord), BLUE);//drawing shifted version of points
			if (cnt == 193 || cnt == 55 || cnt == 435 || cnt == 314 || cnt == 500) {
				cord = new char[getCoordinate.length()];
				strcpy_s(cord, getCoordinate.length() + 1, getCoordinate.c_str());
				settextstyle(2, 0, 500);
				outtextxy(x_AxisMin - 90 , y_AxisMax - Ycord, cord);
			}
			coordinateFile >> getCoordinate;//reading x coordinate
			cnt++;//means point was read.
		}
		coordinateFile.close();//closing file

		cout << "Read Point from File : " << cnt << endl;//printing statistic about number of points read
		cout << "Graphic of those points is printed !!" << endl;//giving information 
		cout << "\nPress E to terminate program"<<endl;//asking user to countinue or not
		terminate=getchar();//getting input

		closegraph();//closing graphic screen
		system("cls");//cleans console
		cnt = 0;//updating counter to zero
	} while (toupper(terminate)!='E');

	return 0;//terminates program properly
}