//Module:	StackClass.h
//Project:	CIS023_S2018_Lab9a Allen Myers
//Author:	Allen Myers
//Date:		March 9th, 2018
//Purpose:	Header file for StackClass.cpp
//			Linked list for stack
//
#pragma once
class StackClass
{
public:
	StackClass();
	~StackClass();

	bool isEmptyStack();			//true if stack is empty
	void push(char);				//ad a node to the stack
	char pop();						//remove node from the stack


private:
	NodeClass*TopNode;				//pointer to top of the stack

};

