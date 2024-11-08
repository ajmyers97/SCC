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
NodeClass::NodeClass(string strIn1, string strIn2,string strIn3,string strIn4,string strIn5)
{
	m_LastName = strIn1;			//store first name
	m_FirstName = strIn2;			//store last name
	m_City = strIn3;				//store city
	m_State = strIn4;				//store state
	m_PhoneNumber = strIn5;			//store phone number

}

string NodeClass::GetLName()
{
	return m_LastName;
}

string NodeClass::GetFName()
{
	return m_FirstName;
}

string NodeClass::GetCity()
{
	return m_City;
}

string NodeClass::GetState()
{
	return m_State;
}

string NodeClass::GetPhoneNumber()
{
	return m_PhoneNumber;
}

TCHAR * NodeClass::GetszName()
{
	//create last name, first name
	string strWork = m_LastName + "," + m_FirstName + "," + m_City + "," + m_State +"," + m_PhoneNumber;

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

void NodeClass::SetCity(string strIn)
{
	m_City = strIn;
}

void NodeClass::SetState(string strIn)
{
	m_State = strIn;
}

void NodeClass::SetPhoneNumber(string strIn)
{
	m_PhoneNumber = strIn;
}
