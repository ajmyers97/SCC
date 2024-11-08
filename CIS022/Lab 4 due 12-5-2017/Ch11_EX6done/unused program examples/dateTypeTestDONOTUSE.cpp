
#include <iostream>
#include <iomanip>
#include "dateType.h"
using namespace std;

int main(){
	dateType date1(3,15,2008);
	date1.print();
	date1.setDate(10,10,2010); 
	date1.print();
	date1.setMonth(12);    
	date1.setDay(12);    
	date1.setYear(2012);    
	date1.print();    
	cout << "Elapsed Days since 1/1/2012 = "<<numberOfDaysPassed()<<endl<<"Days remaining in 2012 = "<< numberOfDaysLeft()<<endl;
	date1.incrementDays(378); //add 378 days to the current date
	cout<<date1.getMonth()<<"/"<<date1.getDay()<<"/"<< date1.getYear()<<"/\n";
	cout<<"There are "<<getDaysInMonth()<< "days in this month\n"<<"and this year "<<isLeapYear() ? "is" : "is not"<<"a leap year.\n";    
	
	return 0;
}