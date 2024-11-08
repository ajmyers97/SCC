//Module:	ZeroException.cpp
//Project:	CIS023_S2018_HW6 Allen Myers
//Author:	Allen Myers
//Date:		March 10th, 2018
//Purpose:	Implementation file for ZeroException Class
//			Exception Class
//
#include "stdafx.h"
#include "ZeroException.h"


ZeroException::ZeroException()
{
	_tcscpy_s(				//load standard error message
		szMessage,
		100,
		TEXT("Zero User Input Error"));

}


ZeroException::~ZeroException()
{
}

ZeroException::ZeroException(TCHAR *szIn)
{
	_tcscpy_s(				//load user provided error message
		szMessage,
		100,
		szIn);
}

TCHAR * ZeroException::what()
{
	return szMessage;
}

