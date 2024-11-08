// Module:		NodeClass.h
// Project:		CIS023_S2018_Lab10a
// Author:		Mark Berrett
// Date:		April 11, 2018
// Purpose:		Header file for NodeClass.cpp
//				Linked list node
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

