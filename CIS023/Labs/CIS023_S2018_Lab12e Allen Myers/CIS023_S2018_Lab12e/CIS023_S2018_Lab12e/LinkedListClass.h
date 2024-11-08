// Module:		LinkedListClass.h
// Project:		CIS023_S2018_Lab12e
// Author:		Mark Berrett
// Date:		May 12, 2018
// Purpose:		Header file for LinkedListClass.cpp
//				Create, fill, navigate, delete linked list
//

#pragma once
class LinkedListClass
{
public:
	LinkedListClass();
	~LinkedListClass();

	void Add();							// append a ball to the list
	void Delete();						// delete the currentBall
	void First();						// make currentBall the 1st ball in the list
	void Next();						// advance currentBall to next ball in list

	BallClass* GetFirstBall();
	BallClass* GetCurrentBall();
	void SetCurrentBall(BallClass*);

private:
	BallClass* firstBall;
	BallClass* lastBall;
	BallClass* currentBall;

};

