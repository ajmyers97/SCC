//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    :  CH2-EX12                                           *
//*                                                                     * 
//* Written by      : Allen J Myers                                     * 
//*                                                                     * 
//* Purpose         : Converts amount of seconds into days, hours,      * 
//*                   minutes and seconds.                              * 
//*                                                                     * 
//*                                                                     * 
//*                                                                     * 
//* Inputs          : User gives a number for seconds                   * 
//*                                                                     * 
//* Outputs         : Converts number into days/hours/minutes/seconds   * 
//*                                                                     * 
//* Calls           : No internal or external calls                     * 
//*                                                                     * 
//* Structure       : BEGIN                                             * 
//*                        Asks user for value                          * 
//*                   STOP                                              * 
//*                        End of Program                               * 
//*                                                                     * 
//*---------------------------------------------------------------------* 
//* Change Log:                                                         * 
//*                         Revision                                    * 
//*       Date    Changed  Rel Ver Mod Purpose                          * 
//* 09/05/17      amyers15 000.000.000 Initial release of program       * 
//*                                                                     * 
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

#include <iostream>
using namespace std;
int main(){
	cout << "Allen Myers\t" << "Ch 2_EX12 \t" << "CH2-EX12.exe" << endl;
	int seconds;
	int days;
	int minutes;
	int remainingSeconds;
	int hours;

	cout<<"Enter a time in seconds: ";
	cin>> seconds;

	const int secondsInMinute=60;
	const int secondsInHour=60* secondsInMinute;
	const int secondsInDay=24*secondsInHour*secondsInMinute;


	days=seconds/secondsInDay;
	hours=seconds/secondsInHour;
	minutes=(seconds/24)/(secondsInMinute);
	remainingSeconds=seconds%secondsInMinute;

	cout<<"The given time is equal to: "<<days<<":"<<hours<<":"<<minutes<<":"<<remainingSeconds<<endl;
	return 0;
}
