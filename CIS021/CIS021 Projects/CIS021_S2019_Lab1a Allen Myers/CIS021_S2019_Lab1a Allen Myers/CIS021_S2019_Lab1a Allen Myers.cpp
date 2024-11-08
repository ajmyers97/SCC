// Project:	CIS021_S2019_Lab1a Allen Myers
// Module:	CIS021_S2019_Lab1a Allen Myers.cpp
// Author:	Allen Myers
// Date:	January 15th, 2019
// Purpose:	Hello world using AND, OR, XOR
//			Review creation of a project in Visual C++.
//			Insert standard project documentation into the main module.
//			Learn how to create a control that will display text on the main window.
//

#include "stdafx.h"						//standard windows program
#include <iostream>						//standard user input output library
#include <iomanip>						//string library

using namespace std;					//standard namespace

int main()
{
	string str1 = "!!!!!!!!!!!";		//mask
	string str2 = "iDMN~vNSME";			//pattern
	string strOut = "";					//destination

	//display values
	cout << "String 1=" << str1 << endl;
	cout << "String 2=" << str2 << endl << endl;
	
	//AND
	cout << "str1 AND str2" << endl;
	for (int i = 0; i < str1.length(); i++)
		strOut += str1[i] & str2[i];
	cout << strOut << endl << endl;			//show resulting string

	//OR
	cout << "str1 OR str2" << endl;
	strOut= "";								//blank output
	for (int i = 0; i < str1.length(); i++)
		strOut += str1[i] | str2[i];
	cout << strOut << endl << endl;			//show resulting string

	//XOR
	cout << "str1 XOR str2" << endl;
	strOut = "";							//blank output
	for (int i = 0; i < str1.length(); i++)
		strOut += str1[i] ^ str2[i];
	cout << strOut << endl << endl;			//show resulting string

	cout << endl << endl;					//show resulting string
	system("Pause");						//pause before closing, it will prompt with press any key to continue

	return 0;
}

