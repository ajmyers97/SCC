//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    : CH2-8                                             * 
//*                                                                     * 
//* Written by      : Allen J Myers                                     * 
//*                                                                     * 
//* Purpose         : To calculate wages from hours worked and          * 
//*                   hourly rate and calculate a value using NUM1      * 
//*                   and NUM2.                                         *
//*                                                                     * 
//*                                                                     * 
//* Inputs          : User inputs values for NUM1, NUM2, NAME &         * 
//*                   HOURSWORKED                                       * 
//* Outputs         : New value from NUM1 and NUM2, and salary.         * 
//*                                                                     * 
//* Calls           : No internal or external calls                     * 
//*                                                                     * 
//* Structure       : BEGIN                                             * 
//*                        Asks user for two values.                    * 
//*                   STOP                                              * 
//*                        Output salary and information for user       * 
//*                                                                     * 
//*---------------------------------------------------------------------* 
//* Change Log:                                                         * 
//*                         Revision                                    * 
//*       Date    Changed  Rel Ver Mod Purpose                          * 
//* 09/05/17      amyers15 000.000.000 Initial release of program       * 
//*                                                                     * 
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 

#include <iostream>
#include <string>

using namespace std;

int main(){
	cout << "Allen Myers\t" << "Ch 2_EX8 \t" << "CH2-EX8.exe" << endl;
	//variable declarations
	int SECRET=11;
	double RATE= 12.50;
	int NUM1,NUM2,NEWNUM;
	string NAME;
	double HOURSWORKED, WAGES;

	//executable statements 
	cout <<"Enter two numbers, with a space: ";
	cin>> NUM1 >> NUM2;
	cout << "The value of num1 is " << NUM1 << " and NUM2 is "<< NUM2<<endl;

	//calculates the value of the new number
	NEWNUM=(NUM1*2)+NUM2;
	cout<<"The value of the new number equals:"<<NEWNUM<<endl;
	//updates NEWNUM with previous NEWNUM and secret number
	NEWNUM=NEWNUM+SECRET;
	cout<<"The value of the new number added with the value of secret equals:"<<NEWNUM<<endl;
	//asks user for last name, #hours worked and calculates their salary
	cout<<"What is your last name?: ";
	cin>> NAME;
	cout<<"How many hours have you worked?: ";
	cin>> HOURSWORKED;
	WAGES=(HOURSWORKED*RATE);

	//outputs the information given to terminal previously
	cout<< "Name: "<< NAME<<endl;
	cout<< "Pay Rate: "<< RATE<<endl;
	cout<< "Hours Worked: "<< HOURSWORKED<<endl;
	cout<< "Salary: "<< WAGES<<endl;
	return 0;
}