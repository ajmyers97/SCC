// Project:		CIS021_S2019_Lab8d
// Module:		LeafClass.h
// Author:		Mark Berrett
// Date:		April 16, 2019
// Purpose:		Header file for LeafClass.cpp
//				B-Tree node data
//

#pragma once
class LeafClass
{
public:
	LeafClass();
	~LeafClass();

	void SetData(char, string);			// sets cLetter and strCode
	char GetLetter();					// returns cLetter
	string GetCode();					// returns strCode;

	void SetLeftLink(LeafClass*);		// sets pointer to left branch
	void SetRightLink(LeafClass*);		// sets pointer to right branch
	LeafClass* GetLeftLink();			// returns pointer to left branch
	LeafClass* GetRightLink();			// returns pointer to right branch

private:
	char cLetter;						// letter of the alphabet (key)
	string strCode;						// code relating to letter

	LeafClass* leftLink;				// pointer to next/left branch
	LeafClass* rightLink;				// pointer to next/right branch
};

