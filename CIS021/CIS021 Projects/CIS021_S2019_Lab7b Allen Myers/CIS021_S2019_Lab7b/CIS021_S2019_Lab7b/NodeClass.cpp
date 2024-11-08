//Project:	CIS021_S2019_Lab7b
//Module:	NodeClass.cpp
//Author:	Allen Myers
//Date:		April 25th, 2019
//Purpose:	Vectors
//
#include "stdafx.h"
#include "NodeClass.h"


NodeClass::NodeClass()
{
}


NodeClass::~NodeClass()
{
}
NodeClass::NodeClass(string strIn1, string strIn2)
{
	m_LastName = strIn1;			//store first name
	m_FirstName = strIn2;			//store last name
}

string NodeClass::GetLName()
{
	return m_LastName;
}

string NodeClass::GetFName()
{
	return m_FirstName;
}

TCHAR * NodeClass::GetszName()
{
	//create last name, first name
	string strWork = m_LastName + "," + m_FirstName;

	//convert to TCHAR
	StringtoTCHAR(&strWork, szReturn);

	return szReturn;			//return combined name as a TCHAR
}

void NodeClass::SetLName(string strIn)
{
	m_LastName = strIn;
}

void NodeClass::SetFName(string strIn)
{
	m_FirstName = strIn;

}
