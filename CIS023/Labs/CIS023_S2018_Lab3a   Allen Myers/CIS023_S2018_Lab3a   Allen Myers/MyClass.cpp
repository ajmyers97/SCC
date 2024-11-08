//Module: MyClass.cpp
//Project:CIS023_S2018_Lab3a   Allen Myers
//Author: Allen Myers
//Date: January 29th, 2018
//Purpose:	Implementation file for MyClass
//

#include "stdafx.h"
#include "MyClass.h"


MyClass::MyClass()
{
	MessageBox(NULL,
		TEXT("MyObject Constructor"),
		TEXT("Myobject"),
		NULL);
}


MyClass::~MyClass()
{
	MessageBox(NULL,
		TEXT("MyObject destructor"),
		TEXT("Myobject"),
		NULL);
}

void MyClass::SayHello()
{
	MessageBox(NULL,
		TEXT("MyObject Message box"),
		TEXT("Myobject"),
		NULL);
}
