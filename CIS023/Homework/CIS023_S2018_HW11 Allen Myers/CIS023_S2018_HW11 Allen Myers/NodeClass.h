// Module:		NodeClass.h
// Project:		CIS023_S2018_HW10
// Author:		Allen Myers
// Date:		April 25th, 2018
// Purpose:		Header file for NodeClass.cpp
//				Node data
//

#pragma once
class NodeClass
{
public:
	NodeClass();
	~NodeClass();

	void SetString(string);				// sets strText
	string GetString();					// returns strString

	void SetLeftLink(NodeClass*);		// sets pointer to left branch
	void SetRightLink(NodeClass*);		// sets pointer to right branch
	NodeClass* GetLeftLink();			// returns pointer to left branch
	NodeClass* GetRightLink();			// returns pointer to right branch

private:
	string strText;						// string from file

	NodeClass* leftLink;				// pointer to next/left branch
	NodeClass* rightLink;				// pointer to next/right branch
};
