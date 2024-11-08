// Project:		CIS021_S2019_Lab8c
// Module:		LeafClass.cpp
// Aurthor:		Mark Berrett
// Date:		April 14, 2019
// Purpose:		Implimentation file for LeafClass
//

#include "stdafx.h"
#include "LeafClass.h"


LeafClass::LeafClass()
{
}


LeafClass::~LeafClass()
{
}

void LeafClass::SetString(string strIn)
{
	strText = strIn;
}

string LeafClass::GetString()
{
	return strText;
}

void LeafClass::SetLeftLink(LeafClass * Node)
{
	leftLink = Node;
}

void LeafClass::SetRightLink(LeafClass * Node)
{
	rightLink = Node;
}

LeafClass * LeafClass::GetLeftLink()
{
	return leftLink;
}

LeafClass * LeafClass::GetRightLink()
{
	return rightLink;
}

