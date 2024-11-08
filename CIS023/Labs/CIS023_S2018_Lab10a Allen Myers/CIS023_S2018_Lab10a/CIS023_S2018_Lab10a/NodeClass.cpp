// Module:		NodeClass.cpp
// Project:		CIS023_S2018_Lab10a
// Author:		Mark Berrett
// Date:		April 11, 2018
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

void NodeClass::SetNextNode(NodeClass * pIn)
{
	nextNode = pIn;
}

NodeClass * NodeClass::GetNextNode()
{
	return nextNode;
}

