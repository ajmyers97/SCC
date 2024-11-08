//Module:	ZeroException.h
//Project:	CIS023_S2018_HW6 Allen Myers
//Author:	Allen Myers
//Date:		March 10th, 2018
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

