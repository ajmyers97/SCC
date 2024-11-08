//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    : CH5_EX16                                           * 
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
#include<cstdlib>
#include<random>
#include<ctime>
#include <cmath>
using namespace std;

int main() {
	cout << "Allen Myers\t" << "Ch5_EX16 \t" << "CH5_EX16.exe" << endl;
	srand(time(0));
	int num = rand() % 100;
	int tries = 0;
	int guess;
	int diff=abs(num-guess);
	bool found  = false;

	while(tries<5){
		cout << "Enter an integer greater than or equal to zero and less than 100: ";
		cin>>guess;
		if (diff>=50){
			cout<<"Your guess is very high\n Guess again!"<<endl;
		}
		else if (diff>=30 && diff<50){
			cout<<"Your guess is high\n Guess again!"<<endl;
		}
		else if (diff>=15 && diff<30){
			cout<<"Your guess is moderately high\n Guess again!"<<endl;
		}
		else if (diff>0 && diff<15){
			cout<<"Your guess is high\n Guess again!"<<endl;
		}
		else if(guess==num){
			found = true;
			break;
		}
		tries++;
		}
	if (found==false){
	    cout<<"You lose! The correct number was "<<num<<endl;
	}
	else if(found==true){
	    cout<<"You win!\n";
	}
}