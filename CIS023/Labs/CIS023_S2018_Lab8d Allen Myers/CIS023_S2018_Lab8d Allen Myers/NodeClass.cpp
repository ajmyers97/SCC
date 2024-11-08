// Module:		NodeClass.cpp
// Project:		CIS023_S2018_Lab8d Key
// Author:		Mark Berrett
// Date:		March 17, 2018
// Purpose:		Implimentation file for NodeClass
//

#include "stdafx.h"
#include "NodeClass.h"


NodeClass::NodeClass()
{
}


NodeClass::~NodeClass()
{
}

NodeClass::NodeClass(string strLName, string strFName, string strCity, string strAge, string strLicense)
{
	size_t pReturnValue;

	// copy input strings to TCHARs
	mbstowcs_s(
		&pReturnValue,
		szLName,
		TCHAR_SIZE,
		strLName.c_str(),
		TCHAR_SIZE
	);

	mbstowcs_s(
		&pReturnValue,
		szFName,
		TCHAR_SIZE,
		strFName.c_str(),
		TCHAR_SIZE
	);

	mbstowcs_s(
		&pReturnValue,
		szCity,
		TCHAR_SIZE,
		strCity.c_str(),
		TCHAR_SIZE
	);

	mbstowcs_s(
		&pReturnValue,
		szAge,
		TCHAR_SIZE,
		strAge.c_str(),
		TCHAR_SIZE
	);

	mbstowcs_s(
		&pReturnValue,
		szLicense,
		TCHAR_SIZE,
		strLicense.c_str(),
		TCHAR_SIZE
	);

	nextNode = nullptr;				// initialize pointers
	prevNode = nullptr;
}


TCHAR* NodeClass::GetLName()
{
	return szLName;
}

TCHAR* NodeClass::GetFName()
{
	return szFName;
}

TCHAR* NodeClass::GetCity()
{
	return szCity;
}

TCHAR* NodeClass::GetAge()
{
	return szAge;
}

TCHAR* NodeClass::GetLicense()
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

