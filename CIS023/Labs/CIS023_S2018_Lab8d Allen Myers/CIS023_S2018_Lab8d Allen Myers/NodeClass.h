// Module:		NodeClass.h
// Project:		CIS023_S2018_Lab8d Key
// Author:		Mark Berrett
// Date:		March 17, 2018
// Purpose:		Header file for NodeClass.cpp
//				Node for linked list
//

#pragma once
class NodeClass
{
public:
	NodeClass();
	~NodeClass();
	NodeClass(string, string, string, string, string);	// overloaded constructor

	TCHAR* GetLName();							// return node data
	TCHAR* GetFName();
	TCHAR* GetCity();
	TCHAR* GetAge();
	TCHAR* GetLicense();

	void SetPrev(NodeClass*);					// set linked list pointers
	void SetNext(NodeClass*);
	NodeClass* GetPrev();						// return linked list pointers
	NodeClass* GetNext();

private:
	TCHAR szLName[TCHAR_SIZE];					// node data, for display return values
	TCHAR szFName[TCHAR_SIZE];
	TCHAR szCity[TCHAR_SIZE];
	TCHAR szAge[TCHAR_SIZE];
	TCHAR szLicense[TCHAR_SIZE];

	NodeClass *prevNode = nullptr;				// pointer to previous node in linked list
	NodeClass *nextNode = nullptr;				// pointer to next node in linked list


};

