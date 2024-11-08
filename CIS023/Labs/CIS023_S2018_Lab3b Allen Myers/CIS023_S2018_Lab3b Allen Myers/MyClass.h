//Module:	CIS023_S2018_Lab3b Allen Myers.cpp
//Project:	CIS023_S2018_Lab3b Allen Myers
//Author:	Allen Myers
//Date:		January 31st, 2018
//Purpose:	Header file for MyClass
//			Convert TCHAR to String
//			Convert string to TCHAR
//

#pragma once
class MyClass
{
public:

	MyClass();

	~MyClass();


	TCHAR* Manipulate(TCHAR*, TCHAR*);	//we need the address of the pointer for what is located in the TCHAR(Converts the TCHAR to string and String to TCHAR)
	TCHAR szReturn[100];		//return value of TCHAR array
};

