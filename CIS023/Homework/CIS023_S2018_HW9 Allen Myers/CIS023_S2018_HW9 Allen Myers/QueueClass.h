//Module:	QueueClass.h
//Project:	CIS023_S2018_HW9 Allen Myers
//Author:	Allen Myers
//Date:		April 12th, 2018
//Purpose:	Learn how to create a queue as a linked list.
//			Initialize, push, pop, and delete a queue.
//			Header file for QueueClass.cpp
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

