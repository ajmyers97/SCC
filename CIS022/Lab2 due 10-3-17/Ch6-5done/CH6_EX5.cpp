//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    : CH6_EX5                                           * 
//*                                                                     * 
//* Written by      : Allen J Myers                                     * 
//*                                                                     * 
//* Purpose         : To cause a message to display on the system       * 
//*                   console. This program will be executed from the   * 
//*                   terminal at the computer room door by personnel   * 
//*                   needing service.                                  * 
//*                                                                     * 
//* Inputs          : User enters HELLO on the terminal command line    * 
//*                                                                     * 
//* Outputs         : Display of entry request on the system terminal   * 
//*                                                                     * 
//* Calls           : No internal or external calls                     * 
//*                                                                     * 
//* Structure       : BEGIN                                             * 
//*                        Straight line code no sub-processes          * 
//*                   STOP                                              * 
//*                        End of Program                               * 
//*                                                                     * 
//*---------------------------------------------------------------------* 
//* Change Log:                                                         * 
//*                         Revision                                    * 
//*       Date    Changed  Rel Ver Mod Purpose                          * 
//* 10/03/17      amyers15 000.000.000 Initial release of program       * 
//*                                                                     * 
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
#include <iostream>
#include<iomanip>
using namespace std;

const double PI=3.1419;
double rectangle(double l, double w);
double circle(double r);
double cylinder(double bR, double h);

int main(){
	cout<<"Allen Myers\t"<<"CH6_EX5\t"<<"CH6_EX5.exe"<<endl;
	double radius,height;
	int choice=0;
	cout<<fixed<<showpoint<<setprecision(2)<<endl;

	while(choice!=-1){
	cout<<"To run the program enter: "<<endl;
	cout<<"1: To find the area of a rectangle."<<endl;
	cout<<"2: To find the area of a circle"<<endl;
	cout<<"3: To find the volume of a cyllinder."<<endl;
	cout<<"-1: to terminate the program."<<endl;
	cin>>choice;
	cout<<endl;
		switch(choice)
		{
			case 1:
			double length, width;
			cout<<"Enter the length and width of the rectangle: ";
			cin>>length>>width;
			cout<<endl;
			cout<<"Area= "<<rectangle(length,width)<<endl;
			break;

			case 2:
			cout<<"Enter the radius of the circle: ";
			cin>>radius;
			cout<<endl;
			cout<<"Area= "<<circle(radius)<<endl;
			break;

			case 3:
			cout<<"Enter the radius of the base and height of the cylinder: ";
			cin>>radius>>height;
			cout<<endl;
			cout<<"Volume= "<<cylinder(radius,height)<<endl;
			break;

			case -1:
			cout<<"exit program"<<endl;
			break;

			default: 
			cout<<"Invalid choice!"<<endl;

		}
	}
	return 0;
}
double rectangle(double l, double w){
	return l*w;
}
double circle(double r){
	return PI*r*r;
}
double cylinder(double bR, double h){
	return PI*bR*h;
}

