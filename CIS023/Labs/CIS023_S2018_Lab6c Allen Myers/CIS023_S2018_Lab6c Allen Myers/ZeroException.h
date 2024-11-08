//Module:	ZeroException.h
//Project:	CIS023_S2018_Lab6c Allen Myers
//Author:	Allen Myers
//Date:		March 5th, 2018
//Purpose:	Header file for ZeroException Class
//
#pragma once
class ZeroException
{
public:
	ZeroException();
	~ZeroException();

	ZeroException(TCHAR*);		//overload with default string

	TCHAR*what();				//returns szMessage

private:
	TCHAR szMessage[100];		//error message
};


