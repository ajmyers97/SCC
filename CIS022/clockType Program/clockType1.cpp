#include<iostream>
#include <iomanip>
#include "clockType1.h"
using namespace std;

clockType1::clockType1(int hours, int minutes, int seconds){
	hr=hours;
	min=minutes;
	sec=seconds;
	++instCount; 
}
void clockType1::setTime(int hours, int minutes, int seconds){
	hr=hours;
	min=minutes;
	sec=seconds;
}
/*void clockType1::getTime(int hours, int minutes, int seconds)const{
	hours=hr;
	minutes=min;
	seconds=sec;
}*/
void clockType1::getTime(int& hours, int& minutes, int& seconds)const{
	hours=hr;
	minutes=min;
	seconds=sec;
}
void clockType1::printTime()const{
	cout<<hr<<":"<<min<<":"<<sec;

}
int clockType1::incrementSec(){
	++sec;
	if(sec>59){
		sec=0;
		incrementMin();
	}
	return sec;

}
int clockType1::incrementMin(){
	++min;
	if(min>59){
		sec=0;
		incrementHr();
	}
	return min;
}
int clockType1::incrementHr(){
	++hr;
	if(hr>23){
		hr=0;
	}
	return hr;
}
bool clockType1::equalTime(clockType1& yourClock)const{
	if(sec==yourClock.sec && min==yourClock.min && hr==yourClock.hr)
		return true;
	else
		return false;

}