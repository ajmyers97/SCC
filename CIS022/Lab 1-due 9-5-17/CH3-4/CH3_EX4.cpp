//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    :   CH3_EX4                                         * 
//*                                                                     * 
//* Written by      : Allen J Myers                                     * 
//*                                                                     * 
//* Purpose         : To convert amount of fertilizer in pounds,        * 
//*                   calculate the cost of it in pounds, and cost to   *
//*					  cover a certain area.                             *
//*                                                                     * 
//* Inputs          : User enters size of fertilizer, and cost and      *
//*						area it covers.									* 
//*                                                                     * 
//* Outputs         : Display cost per pound and per square foot.	    * 
//*                                                                     * 
//* Calls           : No internal or external calls                     * 
//*                                                                     * 
//* Structure       : BEGIN                                             * 
//*                        Prompt for user input.                       * 
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
#include <iomanip>

using namespace std;

int main(){
	cout<<"Allen Myers\t"<<"CH3_EX4\t"<<"CH3_EX4.exe"<<endl;
	double cost;
	double area;
	double bagSize;

	cout<<fixed<<showpoint<<setprecision(2);

	cout<<"Enter the amount of fertilizer, in pounds,"
		<< "in one bag: ";
	cin>>bagSize;
	cout<<endl;
//the errors were the lack of << before "bagSize" on line 47.
	cout<<"Enter the cost of the "<<bagSize<< "pounds fertilizer bag: ";
	cin>>cost;
	cout<<endl;

	cout<<"Enter the area, in square feet, that can be fertilized by one bag: ";
	cin>>area;
	cout<<endl;

	cout<<"The cost of the fertilizer per pound is: $"<<bagSize/cost<<endl;
	cout<<"The cost of fertilizing per square foot is: $"<<area/cost<<endl;

	return 0;

}