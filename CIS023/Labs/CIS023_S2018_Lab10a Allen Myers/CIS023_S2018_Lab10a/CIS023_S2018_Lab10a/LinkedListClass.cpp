// Module:		LinkedListClass.cpp
// Project:		CIS023_S2018_Lab10a
// Author:		Mark Berrett
// Date:		April 11, 2018
// Purpose:		Implimentation file for LinkedListClass
//

#include "stdafx.h"
#include "LinkedListClass.h"

LinkedListClass::LinkedListClass()
{
}


LinkedListClass::~LinkedListClass()
{
	while (firstNode != nullptr)
	{
		NodeClass* tempNode;					// pointer to node
		tempNode = firstNode;					// set to 1st node
		firstNode = firstNode->GetNextNode();	// set 1st node to next node
		delete tempNode;						// delete 1st node
	}
}

void LinkedListClass::Add(string strIn)
{
	NodeClass* newNode = new NodeClass;			// create a new node

	newNode->SetString(strIn);					// save data

	newNode->SetNextNode(nullptr);				// initialize pointer to next node

	if (firstNode == nullptr)					// if the list is empty
	{
		firstNode = newNode;					// then this new node will be the 1st node
		lastNode = newNode;						//	and the last node
	}
	else										// if the list is NOT empty
	{
		lastNode->SetNextNode(newNode);			// this new node will be the last node
		lastNode = newNode;						// point to the last node
	}
}

void LinkedListClass::SetCurrentNode(NodeClass *Node)
{
	currentNode = Node;
}

NodeClass * LinkedListClass::GetCurrentNode()
{
	return currentNode;
}

NodeClass * LinkedListClass::GetFirstNode()
{
	return firstNode;
}

NodeClass * LinkedListClass::GetLastNode()
{
	return lastNode;
}
