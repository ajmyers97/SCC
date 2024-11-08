//Module:	NodeClass.cpp
//Project:	CIS023_S2018_HW9 Allen Myers
//Author:	Allen Myers
//Date:		April 12th, 2018
//Purpose:	Implementation file for NodeClass.cpp.
//			Linked List Code
//
#pragma once
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

void NodeClass::SetNextNode(NodeClass * Node)
{
	nextNode = Node;
}

NodeClass * NodeClass::GetNextNode()
{
	return nextNode;
}
