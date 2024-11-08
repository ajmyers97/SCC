#include<iostream>
#include <iomanip>
#include "clockType1.h"
using namespace std;

int main(){
	clockType1 myClock(11,00,00);
	cout<<"myClock(11,00,00)="<<myClock.instCount<<endl;
	clockType1 yourClock(12,45,00);
	cout<<"yourClock(12,45,00)="<<yourClock.instCount<<endl;

	myClock.setTime(12,00,00);

	for(int i=0;i<60;i++)
		myClock.incrementSec();
	myClock.printTime();
	cout<<endl;
	yourClock.printTime();
	if(myClock.equalTime(yourClock))
		cout<<"The clocks are equla\n";
	else
		cout<<"The clocks are not equal\n";
	return 0;
}