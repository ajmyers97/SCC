//Module:	NodeClass.h
//Project:	CIS023_S2018_Lab9a Allen Myers
//Author:	Allen Myers
//Date:		March 9th, 2018
//Purpose:	Header file for NodeClass.cpp
//			node for stack
//
#pragma once
class NodeClass
{
public:
	NodeClass();
	~NodeClass();

	void SetChar(char);		//store cChar
	char GetChar();		//return cChar

	void SetNextNode(NodeClass*);		//set next node
	NodeClass*GetNextNode();			//return poinyer to next node

private:
	char cChar;			//node data

	NodeClass*nextNode;		//points to the next node

};

