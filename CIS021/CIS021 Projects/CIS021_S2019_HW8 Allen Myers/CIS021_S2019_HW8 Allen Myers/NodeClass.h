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
	NodeClass(string, string, string, string, string);
	//accesors
	string GetLName();		//return m_LastName
	string GetFName();		//return m_FirstName
	string GetCity();		//return m_City
	string GetState();		//return m_State
	string GetPhoneNumber();//return m_PhoneNumber

	TCHAR *GetszName();		//return combined name as a TCHAR

							//mutators
	void SetLName(string);	//store m_LastName
	void SetFName(string);	//store m_FirstName
	void SetCity(string);
	void SetState(string);
	void SetPhoneNumber(string);



private:
	string m_LastName;		//data, last name
	string m_FirstName;		//data, first name
	string m_City;			//city
	string m_State;			//state
	string m_PhoneNumber;	//phone number 

	TCHAR szReturn[TCHAR_SIZE];	//return value for GetszName()
};

