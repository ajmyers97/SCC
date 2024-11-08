//Module:	QueueClass.cpp
//Project:	CIS023_S2018_HW9 Allen Myers
//Author:	Allen Myers
//Date:		April 12th, 2018
//Purpose:	Learn how to create a queue as a linked list.
//			Initialize, push, pop, and delete a queue.
//			Implementation file for QueueClass.cpp

#include "stdafx.h"
#include "QueueClass.h"


QueueClass::QueueClass()
{
}


QueueClass::~QueueClass()
{
	while (!isEmptyQueue())				//delete all nodes
		getQueue();						//by getting the node0

}


void QueueClass::initializeQueue()
{
	topNode = nullptr;					//initialize pointers to nullptr
	bottomNode = nullptr;

}

bool QueueClass::isEmptyQueue()
{
	if (topNode == nullptr)					//is the queue empty
		return true;
	return false;
}

void QueueClass::addQueue(char cIn)
{
	NodeClass*newNode = new NodeClass;		//create a new node
	newNode->SetChar(cIn);					//store the data
	newNode->SetNextNode(nullptr);			//initialize the link

	if (isEmptyQueue())						//is this the first ndoe in the list
	{
		topNode = newNode;					//top and bottom nodes will be this new node
		bottomNode = newNode;

	}
	else
	{
		bottomNode->SetNextNode(newNode);	//old bottom node points to this new node
		bottomNode = newNode;				//new node now bottom node
	}


}

char QueueClass::getQueue()
{
	if (isEmptyQueue())						//if the queue is empty
		return NULL;						//then ntohign to do or return
	char cReturn = topNode->GetChar();		//data from node

	NodeClass*tempNode;						//temp pointer
	tempNode = topNode;						//hold pointer to top node
	topNode = topNode->GetNextNode();		//advance top node
	delete tempNode;						//delete top node

	if (topNode == nullptr)					//was this the last node in the list
		bottomNode = nullptr;				//then bottom node should point to nullptr

	return cReturn;				//return data
}
