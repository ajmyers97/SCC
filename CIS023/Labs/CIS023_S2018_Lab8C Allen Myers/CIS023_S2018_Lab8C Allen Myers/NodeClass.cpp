//Module:	NodeClass.cpp
//Project:	CIS023_S2018_Lab8C Allen Myers
//Author:	Allen Myers
//Date:		March 26th, 2018
//Purpose:	implementation file for NodeClass.cpp
//			node code
//
#include "stdafx.h"
#include "NodeClass.h"


NodeClass::NodeClass()
{
}


NodeClass::~NodeClass()
{
}

NodeClass::NodeClass(string str1, string str2, string str3, string str4, string str5)
{
	size_t pRet;				//return value for mbstowcs_s()

	mbstowcs_s(					//copy strign to TCHAR
		&pRet,					//return value
		szLName,				//destination
		TCHAR_SIZE,				//size of destination
		str1.c_str(),			//source string
		TCHAR_SIZE				//max number of chars to copy
		);
	mbstowcs_s(					//copy strign to TCHAR
		&pRet,					//return value
		szFName,				//destination
		TCHAR_SIZE,				//size of destination
		str2.c_str(),			//source string
		TCHAR_SIZE				//max number of chars to copy
		);
	mbstowcs_s(					//copy strign to TCHAR
		&pRet,					//return value
		szCity,				//destination
		TCHAR_SIZE,				//size of destination
		str3.c_str(),			//source string
		TCHAR_SIZE				//max number of chars to copy
		);
	mbstowcs_s(					//copy strign to TCHAR
		&pRet,					//return value
		szAge,				//destination
		TCHAR_SIZE,				//size of destination
		str4.c_str(),			//source string
		TCHAR_SIZE				//max number of chars to copy
		);
	mbstowcs_s(					//copy strign to TCHAR
		&pRet,					//return value
		szLicense,				//destination
		TCHAR_SIZE,				//size of destination
		str5.c_str(),			//source string
		TCHAR_SIZE				//max number of chars to copy
		);
	prevNode = nullptr;			//initialize pointers
	nextNode = nullptr;




}

TCHAR * NodeClass::GetLName()
{
	return szLName;
}

TCHAR * NodeClass::GetFName()
{
	return szFName;
}

TCHAR * NodeClass::GetCity()
{
	return szCity;
}

TCHAR * NodeClass::GetAge()
{
	return szAge;
}

TCHAR * NodeClass::GetLicense()
{
	return szLicense;
}

void NodeClass::SetPrev(NodeClass * Node)
{
	prevNode = Node;
}

void NodeClass::SetNext(NodeClass * Node)
{
	nextNode = Node;
}

NodeClass * NodeClass::GetPrev()
{
	return prevNode;
}

NodeClass * NodeClass::GetNext()
{
	return nextNode;
}

void NodeClass::Copy(NodeClass * thatNode)
{
	_tcscpy_s(szLName, thatNode->GetLName());
	_tcscpy_s(szFName, thatNode->GetFName());
	_tcscpy_s(szCity, thatNode->GetCity());
	_tcscpy_s(szAge, thatNode->GetAge());
	_tcscpy_s(szLicense, thatNode->GetLicense());




}
