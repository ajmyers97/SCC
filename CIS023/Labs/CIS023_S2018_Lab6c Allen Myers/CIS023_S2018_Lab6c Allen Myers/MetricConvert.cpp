//Module:	MetricConvert.cpp
//Project:	CIS023_S2018_Lab6c Allen Myers
//Author:	Allen Myers
//Date:		March 5th, 2018
//Purpose:	Implementation File for MetricConvert
//			Using exception handling
//
//
#include "stdafx.h"
#include "MetricConvert.h"

class Zero{};				//exception class
class Negative{};			//exception class


MetricConvert::MetricConvert()
{
	erase();				//default, erase the base class string
}


MetricConvert::~MetricConvert()
{
}

TCHAR * MetricConvert::GetCM()
{
	//double dInches = 0.0;			//converted form string base class value
	//double dCentimeters = 0.0;		//iInches=2.54cm
	//dInches = atof(c_str());		//conert from base string to decimal
	//dCentimeters = dInches*2.54;	//calculate centimeters
	
	//_stprintf_s(					//convert double to TCHAR
	//	szReturn,					//target TCHAR
	//	TEXT("%f"),					//template
	//	dCentimeters);				//source number

	///////////////////////
	//with exception handling
	double dInches = 0.0;			//converted form string base class value
	double dCentimeters = 0.0;		//iinches=2.54cm

	_tcscpy_s(						//blank return value just incase
		szReturn,
		100,
		TEXT("")
	);

	if (empty())						//if the base class string value is empty
		return szReturn;				//the constructor caught it

	try
	{
		dInches = atof(c_str());		//conert from base string to decimal
		if (dInches == 0.0)				//bad value(text in umber) or they entered zero
			throw Zero();
		dCentimeters = dInches*2.54;	//calculate centimeters

		_stprintf_s(					//convert double to TCHAR
			szReturn,					//target TCHAR
			TEXT("%f"),					//template
			dCentimeters);				//source number
	}	
	catch (Zero)
	{
		MessageBox(							//message box
			NULL,							//floating
			TEXT("0 INCHES=0CENTIMETERS"),	//message
			TEXT("UNACCEPTABLE INPUT"),			//caption
			MB_ICONERROR);					//icon

	}
	return szReturn;
}

TCHAR * MetricConvert::GetIN()
{
	//double dInches = 0.0;			//iInches=2.54cm 
	//double dCentimeters = 0.0;		//iInches=2.54cm converted form string base class value

	//dCentimeters = atof(c_str());	//convert from base string to decimal

	//dInches = dCentimeters/2.54;	//calculate centimeters


	//_stprintf_s(					//convert double to TCHAR
	//	szReturn,					//target TCHAR
	//	TEXT("%f"),					//template
	//	dInches);					//source number

	////////////////////////
	//with exception handling
	double dInches = 0.0;			//iInches=2.54cm 
	double dCentimeters = 0.0;		//iInches=2.54cm converted form string base class value

	if (empty())						//if the base class string value is empty
		return szReturn;				//the constructor caught it
	try
	{
		dCentimeters = atof(c_str());	//convert from base string value to decimal
		if (dCentimeters < 0)				//if user input a negative number
			throw Negative();				//throw an exception
		else if (dCentimeters == 0)			//if user input a 0(or invalid value)
			throw ZeroException(
			TEXT("INVALID ENTRY: PLEASE INPUT A NUMERIC VALUE"));			//throw an exception form the class


		dInches = dCentimeters / 2.54;		//calculates inches
		_stprintf_s(szReturn, TEXT("%f"), dInches);	//convert decimal to TCHAr


	}
	catch (Negative)
	{
		MessageBox(							//message box
			NULL,							//floating
			TEXT("Negative values are okay of course, but this time let's keep it positive."),	//message
			TEXT("NEGATIVE INPUT"),			//caption
			MB_ICONHAND);					//icon

	}
	catch (ZeroException ze)
	{
		MessageBox(							//ERROR MESSAGE
			NULL,							//floating
			ze.what(),						//USING MESSAGE FROME XCEPTIO CLASS ZERO EXCEPTION
			TEXT("INPUT ERROR"),			//caption
			MB_ICONASTERISK);				//icon
	}

	return szReturn;
}

MetricConvert::MetricConvert(TCHAR *szIn)
{
	//wstring temp(szin);				//convert tchar to stream
	//string str(temp.begin(),		//convert stream to string
	//	temp.end());
	//store string in base class
	//erase();						//expties base class
	//append(str);					//add user input to base class string

	///////////////////////////////
	//with exception handling
	erase();						//empties base class
	try
	{
		if (lstrlen(szIn) == 0)		//if user input is empty
			throw 1;				//throw an exception
		wstring temp(szIn);				//convert tchar to stream
		string str(temp.begin(),		//convert stream to string
			temp.end());

		append(str);					//some string in base class


	}
	catch (int)
	{	
		MessageBox(							//message box
			NULL,							//floating
			TEXT("PLEASE INPUT A VALUE"),	//message
			TEXT("INPUT ERROR"),			//caption
			MB_ICONERROR);					//icon
	}
}
