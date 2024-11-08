//Module:	NodeClass.cpp
//Project:	CIS023_S2018_Lab9a Allen Myers
//Author:	Allen Myers
//Date:		March 9th, 2018
//Purpose:	implementation file for NodeClass.cpp
//			node for stack
//
#include "stdafx.h"
#include "NodeClass.h"


NodeClass::NodeClass()
{
}


NodeClass::~NodeClass()
{
}

void NodeClass::SetChar(char c)
{
	cChar = c;
}


char NodeClass::GetChar()
{
	return cChar;
}

void NodeClass::SetNextNode(NodeClass *Node)
{
	nextNode = Node;

}

NodeClass * NodeClass::GetNextNode()
{
	return nextNode;
}
