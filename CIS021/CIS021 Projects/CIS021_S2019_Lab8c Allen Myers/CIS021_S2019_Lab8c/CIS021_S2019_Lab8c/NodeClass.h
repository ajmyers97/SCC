// Project:		CIS021_S2018_Lab8c
// Module:		NodeClass.h
// Aurthor:		Mark Berrett
// Date:		April 14, 2019
// Purpose:		Header file for NodeClass.cpp
//				Storage class for Linked list
//

#pragma once
class NodeClass
{
public:
	NodeClass();
	~NodeClass();

	void SetString(string);				// sets strText
	string GetString();					// returns strText

	void SetNextNode(NodeClass*);		// sets pointer to next node
	NodeClass* GetNextNode();			// returns pointer to next node

private:
	string strText;						// string from file

	NodeClass* nextNode;				// pointer to next node

};

