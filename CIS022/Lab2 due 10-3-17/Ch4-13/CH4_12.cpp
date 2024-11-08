//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    : CH4_EX13                                          * 
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
#include<string>
using namespace std;

int main(){
	cout<<"Allen Myers\t"<<"CH4_EX13\t"<<"CH4_EX13.exe"<<endl;
	double length,width,leftMargin,rightMargin,bottomMargin,topMargin,pointSize;
	char spacing;
	int charNum,lineNum;

	cout<<"Enter length of paper: ";
	cin>>length;
	cout<<"Enter width of paper: ";
	cin>>width;
	cout<<"Enter left margin of paper: ";
	cin>>leftMargin;
	cout<<"Enter right margin of paper: ";
	cin>>rightMargin;
	cout<<"Enter top margin of paper: ";
	cin>>topMargin;
	cout<<"Enter bottom margin of paper: ";
	cin>>bottomMargin;
	cout<<"Enter point size of char: ";
	cin>>pointSize;
	cout<<"Enter line spacing, s or S(single space), d or D(double space): ";
	cin>>spacing;
///?????????
	if((spacing='d')||(spacing='D'))
		pointSize=(pointSize*2);
		width=width/2;

	length=(length-(topMargin+bottomMargin));
	width=(width-(rightMargin+leftMargin));
	charNum=(2*((width*(72))/(pointSize)));
	pointSize=(pointSize/72);
	lineNum=(length/pointSize);
///?????????

	cout<<"The number of lines that can be printed: "<<lineNum<<endl;
	cout<<"The number of characters that can be printed in a line: "<<charNum<<endl;

	return 0;

}