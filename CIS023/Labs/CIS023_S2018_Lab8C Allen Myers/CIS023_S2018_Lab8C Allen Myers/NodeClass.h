//Module:	NodeClass.h
//Project:	CIS023_S2018_Lab8C Allen Myers
//Author:	Allen Myers
//Date:		March 26th, 2018
//Purpose:	Header file for NodeClass.cpp
//			node code
//
#pragma once
class NodeClass
{
public:
	NodeClass();
	~NodeClass();

	NodeClass(string, string, string, string, string);	//overloaded constrcutor

	TCHAR*GetLName();									//return data
	TCHAR*GetFName();
	TCHAR*GetCity();
	TCHAR*GetAge();
	TCHAR*GetLicense();

	void SetPrev(NodeClass*);							//set prevNode
	void SetNext(NodeClass*);							//set nextNode
	NodeClass*GetPrev();								//return prevNode
	NodeClass*GetNext();								//return nextNode
	
	void Copy(NodeClass*);						//deep copy from that to this

private:
	TCHAR szLName[TCHAR_SIZE];							//node data
	TCHAR szFName[TCHAR_SIZE];
	TCHAR szAge[TCHAR_SIZE];
	TCHAR szCity[TCHAR_SIZE];
	TCHAR szLicense[TCHAR_SIZE];	

	NodeClass*prevNode;									//pointer to previous node
	NodeClass*nextNode;									//pointer to next node
};

