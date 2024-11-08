//Project:	CIS021_S2019_Lab7b
//Module:	NodeClass.h
//Author:	Allen Myers
//Date:		April 25th, 2019
//Purpose:	Vectors
//
#pragma once
class NodeClass
{
public:
	NodeClass();
	~NodeClass();
	NodeClass(string, string);
	//accesors
	string GetLName();		//return m_LastName
	string GetFName();		//return m_FirstName
	TCHAR *GetszName();		//return combined name as a TCHAR

	//mutators
	void SetLName(string);	//store m_LastName
	void SetFName(string);	//store m_FirstName

private:
	string m_LastName;		//data, last name
	string m_FirstName;		//data, first name

	TCHAR szReturn[TCHAR_SIZE];	//return value for GetszName()
};

