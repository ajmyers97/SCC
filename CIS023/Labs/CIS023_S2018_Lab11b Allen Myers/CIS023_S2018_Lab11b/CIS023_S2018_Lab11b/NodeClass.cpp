// Module:		NodeClass.cpp
// Project:		CIS023_S2018_Lab11b
// Author:		Mark Berrett
// Date:		April 14, 2018
// Purpose:		Implimentation file for NodeClass
//

#include "stdafx.h"
#include "NodeClass.h"


NodeClass::NodeClass()
{
}


NodeClass::~NodeClass()
{
}

void NodeClass::SetString(string strIn)
{
	strText = strIn;
}

string NodeClass::GetString()
{
	return strText;
}

void NodeClass::SetLeftLink(NodeClass * Node)
{
	leftLink = Node;
}

void NodeClass::SetRightLink(NodeClass * Node)
{
	rightLink = Node;
}

NodeClass * NodeClass::GetLeftLink()
{
	return leftLink;
}

NodeClass * NodeClass::GetRightLink()
{
	return rightLink;
}

