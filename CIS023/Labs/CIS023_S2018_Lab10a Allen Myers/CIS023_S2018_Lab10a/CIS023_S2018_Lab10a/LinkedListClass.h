// Module:		LinkedListClass.h
// Project:		CIS023_S2018_Lab10a
// Author:		Mark Berrett
// Date:		April 11, 2018
// Purpose:		Header file for LinkedListClass.cpp
//				Linked list
//

#pragma once
class LinkedListClass
{
public:
	LinkedListClass();
	~LinkedListClass();

	void Add(string);							// add a new node

	void SetCurrentNode(NodeClass*);			// set the current node
	NodeClass* GetCurrentNode();				// get the current node
	NodeClass* GetFirstNode();					// get the first node
	NodeClass* GetLastNode();					// get the last node

private:
	NodeClass* firstNode;						// pointer to first node
	NodeClass* lastNode;						// pointer to last node
	NodeClass* currentNode;						// pointer to the current node

};

