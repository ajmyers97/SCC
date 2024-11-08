
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    : CH4_EX13                                          * 
//*                                                                     * 
//* Written by      : Allen J Myers                                     * 
//*                                                                     * 
//* Purpose         : To cause a message to display on the system       * 
//*                   console. This program will be executed from the   * 
//*                   terminal at the computer room door by personnel   * 
//*                   needing service.                                  * 
//*                                                                     * 
//* Inputs          : User enters HELLO on the terminal command line    * 
//*                                                                     * 
//* Outputs         : Display of entry request on the system terminal   * 
//*                                                                     * 
//* Calls           : No internal or external calls                     * 
//*                                                                     * 
//* Structure       : BEGIN                                             * 
//*                        Straight line code no sub-processes          * 
//*                   STOP                                              * 
//*                        End of Program                               * 
//*                                                                     * 
//*---------------------------------------------------------------------* 
//* Change Log:                                                         * 
//*                         Revision                                    * 
//*       Date    Changed  Rel Ver Mod Purpose                          * 
//* 10/03/17      amyers15 000.000.000 Initial release of program       * 
//*                                                                     * 
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
#include <iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

int main(){
	double accountBalance,withdrawAmnt,serviceCharge,updatedBalance;
	ifstream inData;
	ofstream outData;
	inData.open("Ch4_Ex15_Data.txt");

	cout<<"Allen Myers\t"<<"CH4_EX13\t"<<"CH4_EX13.exe"<<endl;
	inData>>accountBalance;
	cout<<"The account balance before withdrawal:$ "<<accountBalance<<endl;
	cout<<"Enter the amount you would like to withdraw: "<<endl;
	cin>>withdrawAmnt;
	cout<<endl;

	//inData>>accountBalance>>endl;
	outData<<updatedBalance<<endl;

	if(withdrawAmnt>500){
		cout<<"Limit is $500"<<endl;
	}
	else if((withdrawAmnt>300)&& (withdrawAmnt<500)){
		serviceCharge=((withdrawAmnt-300)*(.04));
		withdrawAmnt=(withdrawAmnt+serviceCharge);
		updatedBalance=(accountBalance-withdrawAmnt);
		cout<<"Collect your money"<<endl;
		cout<<"accountBalance after withdrawal:$ "<<updatedBalance<<endl;
		cout<<"Service Charge is:$ "<<serviceCharge<<endl;
	}
	else if(accountBalance<withdrawAmnt){
		serviceCharge=((withdrawAmnt-300)*(.04));
		withdrawAmnt=(withdrawAmnt+serviceCharge+25);
		updatedBalance=(accountBalance-withdrawAmnt);
		cout<<"Collect your money"<<endl;
		cout<<"accountBalance after withdrawal:$ "<<updatedBalance<<endl;
		cout<<"Service Charge is:$ "<<serviceCharge<<endl;
	}
	else if(accountBalance<=0){
		cout<<"insufficient funds"<<endl;
	}
	inData.close();
	outData.close();
	return 0;

}





