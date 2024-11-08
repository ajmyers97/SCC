//Module:	NodeClass.h
//Project:	CIS023_S2018_Lab9b
//Author:	Allen Myers
//Date:		April 11th, 2018
//Purpose:	Header file for NodeClass.cpp.
//			Linked List Code
//
#pragma once
class NodeClass
{
public:
	NodeClass();
	~NodeClass();

	void SetChar(char);			//store cChar
	char GetChar();

	void SetNextNode(NodeClass*);	//set nextnode
	NodeClass*GetNextNode();		//return next node


private:
	char cChar;				//node data

	NodeClass*nextNode;		//pointer to next node
};


