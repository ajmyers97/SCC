//Module:	NodeClass.cpp
//Project:	CIS023_S2018_Lab11a
//Author:	Allen Myers	
//Date:		April 23rd, 2018
//Purpose:	Implementation File for NodeClass.cpp
//			Data for individual bTree nodes	
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

void NodeClass::SetLeftLink(NodeClass *node)
{
	leftLink = node;

}

void NodeClass::SetRightLink(NodeClass *node)
{
	rightLink = node;
}

NodeClass * NodeClass::GetLeftLink()
{
	return leftLink;
}

NodeClass * NodeClass::GetRightLink()
{
	return rightLink;
}
