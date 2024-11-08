//clockType1.h
//#pragma once;
class clockType1{
	private:
		int hr;
		int min;
		int sec;

	public:
	int static instCount;
	clockType1(int hr=0, int min=0, int sec=0);
	void setTime(int, int, int);
	void getTime(int&, int&, int&) const;
	void printTime()const;
	int incrementSec();
	int incrementMin();
	int incrementHr();
	bool equalTime(clockType1&)const;

};