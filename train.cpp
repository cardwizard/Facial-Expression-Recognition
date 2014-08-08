#include <iostream>
#include <cv.h>
#include <highgui.h>
#include <fstream>
#include <sstream>
#include <string.h>
#include <ctype.h>

using namespace std;
using namespace cv;

int main()
{
	int i=0,j,limit=50;
string dir,dir3,expr,enter,csv=".csv";
string dir2="mkdir ";

VideoCapture stream1(0);

if(!stream1.isOpened())
{
cout<< "\nCannot open camera\n";
exit(0);
}

cout<<" \nEnter your name ";
cin>>dir;

dir3=dir2+dir;
enter=enter+dir;
//cout<<dir3;
system(dir3.c_str());


//waitKey(0);

expr=dir2+format("%s/happy",dir.c_str());
system(expr.c_str());

expr=dir2+format("Facerec/%s",dir.c_str());
system(expr.c_str());

while(true)
{
	i++;
	Mat image;
	stream1.read(image);
	//imshow("Getready",image);
	waitKey(33);
	if(i>100)
		break;
}

cout<<"Happy";
cin>>j;

i=0;

while(true)
{
	i++;
	string name;

	Mat image;
//	waitKey(0);
	stream1.read(image);
	
	imwrite(format("%s/happy/%d.jpg",dir.c_str(),i),image);
	
	if(i>limit)
		break;

	if(i>(limit-25))
	imwrite(format("Facerec/%s/%d.jpg",dir.c_str(),i+10),image);
	//imshow("happy",image);
//	waitKey(0);
}

cout<<" Done ";

while(true)
{
	i++;
	Mat image;
	stream1.read(image);
	//imshow("Getready",image);
	waitKey(33);
	if(i>100)
		break;
}

i=0;

cout<<"Sad: ";
cin>>j;

expr=dir2+format("%s/sad",dir.c_str());
system(expr.c_str());

while(true)
{
	
	i++;
	string name;

	Mat image;
//	waitKey(0);
	stream1.read(image);
	
	imwrite(format("%s/sad/%d.jpg",dir.c_str(),i),image);
	if(i>limit)
		break;
	if(i>(limit-25))
	imwrite(format("Facerec/%s/%d.jpg",dir.c_str(),i+20),image);
	//imshow("sad",image);
//	waitKey(0);
}

cout<<" Done ";

while(true)
{
	i++;
	Mat image;
	stream1.read(image);
	//imshow("Getready",image);
	waitKey(33);
	if(i>100)
		break;
}

i=0;

cout<<"surprised: ";
cin>>j;
//waitKey(0);
 
expr=dir2+format("%s/surprised",dir.c_str());
system(expr.c_str());

while(true)
{

	i++;
	string name;

	Mat image;
//	waitKey(0);
	stream1.read(image);
	
	imwrite(format("%s/surprised/%d.jpg",dir.c_str(),i),image);
	if(i>limit)
		break;
	if(i>(limit-25))
	imwrite(format("Facerec/%s/%d.jpg",dir.c_str(),i+30),image);

	//imshow("surprised",image);
//	waitKey(0);

}

cout<<" Done ";

while(true)
{
	i++;
	Mat image;
	stream1.read(image);
	//imshow("Getready",image);
	waitKey(33);
	if(i>100)
		break;
}

//destroyWindow("Getready");
i=0;

expr=dir2+format("%s/disgust",dir.c_str());
system(expr.c_str());

cout<<"Disgust: ";
cin>>j;
//waitKey(0);

while(true)
{
	i++;
	string name;

	Mat image;
	//waitKey(0);
	stream1.read(image);
	
	imwrite(format("%s/disgust/%d.jpg",dir.c_str(),i),image);
	if(i>limit)
		break;
    
    if(i>(limit-25))
	imwrite(format("Facerec/%s/%d.jpg",dir.c_str(),i+40),image);
	//imshow("disgust",image);
//	waitKey(0);
}

cout<<" Done ";

//cout<<"\n Creating CSV Files";

string csvcreator = "python create_csv.py ";

string facecsv=csvcreator+"Facerec "+"Facerec.csv";

system(facecsv.c_str());

csvcreator+=dir;

string space=" ";
csvcreator+=space;
string final=format("%s.csv",dir.c_str());
csvcreator+=final;
//cout<<csvcreator.c_str();

system(csvcreator.c_str());

/*cout<<"\n Starting the recognizer: ";

/*for(i=0;i<50;i++)
destroyAllWindows();

/*cout<<"\n Start Tester: ";
cin>>j;

//ystem("g++ `pkg-config --cflags opencv` test3.cpp `pkg-config --libs opencv` -o h");

/*cout<<"\n Press 1: ";
cin>>j;

csv="./t "+ dir + csv + " hello";


system(csv.c_str());
*/
return 0;
}
