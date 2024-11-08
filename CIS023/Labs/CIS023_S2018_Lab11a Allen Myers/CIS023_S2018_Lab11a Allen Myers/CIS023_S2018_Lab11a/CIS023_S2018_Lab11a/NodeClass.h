//Module:	NodeClass.h
//Project:	CIS023_S2018_Lab11a
//Author:	Allen Myers	
//Date:		April 23rd, 2018
//Purpose:	Header File for NodeClass.cpp
//			Data for individual bTree nodes	
//			
//			
#pragma once
class NodeClass
{
public:
	NodeClass();
	~NodeClass();
	void SetString(string);		//sets strText
	string GetString();			//returns strText
	void SetLeftLink(NodeClass*);	//sets left link
	void SetRightLink(NodeClass*);	//sets right link
	NodeClass*GetLeftLink();		//return leftlink
	NodeClass*GetRightLink();	//return rightlink

private:
	string strText;				//string from file
	NodeClass*leftLink;			//pointer to the next/left branch
	NodeClass*rightLink;		//pointer to the next/right branch



};

