// Module:		NodeClass.h
// Project:		CIS023_S2018_Lab10b
// Developer:	Mark Berrett
// Date:		April 11, 2018
// Purpose:		Header file for NodeClass.cpp
//				Linked list node data
//

#pragma once
class NodeClass
{
public:
	NodeClass();
	~NodeClass();

	void SetString(string);				// sets strString
	string GetString();					// returns strString

	void SetNextNode(NodeClass*);		// sets pointer to next node
	void SetPrevNode(NodeClass*);		// sets pointer to previous node
	NodeClass* GetNextNode();			// returns pointer to next node
	NodeClass* GetPrevNode();			// returns pointer to previous node

private:
	string strText;						// string from file

	NodeClass* nextNode;				// pointer to next node
	NodeClass* prevNode;				// pointer to [revopios node
};

