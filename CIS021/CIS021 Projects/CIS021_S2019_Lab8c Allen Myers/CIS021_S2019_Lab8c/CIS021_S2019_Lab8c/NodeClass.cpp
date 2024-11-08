// Project:		CIS021_S2019_Lab8c
// Module:		NodeClass.cpp
// Author:		Mark Berrett
// Date:		April 14, 2019
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

