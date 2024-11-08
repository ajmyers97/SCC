//Module:	StackClass.cpp
//Project:	CIS023_S2018_Lab9a Allen Myers
//Author:	Allen Myers
//Date:		March 9th, 2018
//Purpose:	Implementation file for StackClass.cpp
//			Linked list for stack
//
#include "stdafx.h"
#include "StackClass.h"


StackClass::StackClass()
{
	TopNode = nullptr;				//NEW STACK IS EMPTY
}


StackClass::~StackClass()
{

	while (!isEmptyStack())			//pop untilt the stack is empty
		pop();
}

bool StackClass::isEmptyStack()
{

	if (TopNode == nullptr)			//if the stack is empty
		return TRUE;

	return FALSE;					//if the stack is not empty
}
//push one data element(node) onto the stack
void StackClass::push(char inC)
{
	NodeClass*newNode = new NodeClass;	//create  a new node
	newNode->SetChar(inC);				//set the data
	newNode->SetNextNode(nullptr);		//initialize pointer to next node

	if (!isEmptyStack())					//uf there's anothe rnode in the stack
		newNode->SetNextNode(TopNode);		//set pointer to next node

	TopNode = newNode;						//this is the new top node



}

//pop one data element (node) off of the stack and returns its data
char StackClass::pop()
{
	if (isEmptyStack())					//if the stack is empty
		return NULL;					//then there is nothing to return
	char cReturn = TopNode->GetChar();	//set return value

	NodeClass*tempNode;					//pointer to a temp node
	tempNode = TopNode->GetNextNode();	//point temp to nex node
	delete TopNode;						//delete the top node
	TopNode = tempNode;					//next node is not top node

	return cReturn;						//return the data from the former top node
}
