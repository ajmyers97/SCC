// Project:		CIS021_S2019_Lab8d
// Module:		LeafClass.cpp
// Author:		Mark Berrett
// Date:		April 16, 2019
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

void LeafClass::SetData(char c, string s)
{
	cLetter = c;
	strCode = s;
}

char LeafClass::GetLetter()
{
	return cLetter;
}

string LeafClass::GetCode()
{
	return strCode;
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

