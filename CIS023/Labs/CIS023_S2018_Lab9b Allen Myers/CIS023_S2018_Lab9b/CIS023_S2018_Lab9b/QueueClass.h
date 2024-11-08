//Module:	QueueClass.h
//Project:	CIS023_S2018_Lab9b
//Author:	Allen Myers
//Date:		April 11th, 2018
//Purpose:	Header file for QueueClass.cpp.
//			Linked List
#pragma once
#pragma once
class QueueClass
{
public:
	QueueClass();
	~QueueClass();

	void initializeQueue();		//initialize the queue
	bool isEmptyQueue();		//true if queue is empty
	void addQueue(char);		//add a node to the queue
	char getQueue();			//delete a node from the queue, return the data


private:
	NodeClass*topNode;			//1st node in the list
	NodeClass*bottomNode;		//last node in the list

};

