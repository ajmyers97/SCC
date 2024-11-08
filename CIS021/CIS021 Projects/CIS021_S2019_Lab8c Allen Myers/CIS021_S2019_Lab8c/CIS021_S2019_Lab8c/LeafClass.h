// Project:		CIS021_S2018_Lab8c
// Module:		LeafClass.h
// Aurthor:		Mark Berrett
// Date:		April 14, 2019
// Purpose:		Header file for LeafClass.cpp
//				Node storage class for bTree
//

#pragma once
class LeafClass
{
public:
	LeafClass();
	~LeafClass();

	void SetString(string);				// sets strText
	string GetString();					// returns strString

	void SetLeftLink(LeafClass*);		// sets pointer to left branch
	void SetRightLink(LeafClass*);		// sets pointer to right branch
	LeafClass* GetLeftLink();			// returns pointer to left branch
	LeafClass* GetRightLink();			// returns pointer to right branch

private:
	string strText;						// string from file

	LeafClass* leftLink;				// pointer to next/left branch
	LeafClass* rightLink;				// pointer to next/right branch
};

