//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    : CH7_EX6.exe                                       * 
//*                                                                     * 
//* Written by      : Allen J Myers                                     * 
//*                                                                     * 
//* Purpose         : To cause a message to display on the system       * 
//*                   console. This program will be executed from the   * 
//*                   terminal at the computer room door by personnel   * 
//*                   needing service.                                  * 
//*                                                                     * 
//* Inputs          : User enters a choice on the terminal command line * 
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
//* 11/2/17       amyers15 000.000.000 Initial release of program       * 
//*                                                                     * 
//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
//code for functions borrowed from dreamincode.net
//code for switch statment borrowed from cplusplus.com
int doubleNum(int x);
int revNum(int x);
int powNum(int x);
int sumNum(int x);
int firstToSecond(int x);
int firstTwoToLast(int x);
int primeNum(int x);
int lessThanTen (int x);
void printFunction(int x, int y);

int main(){
        cout<<"Allen Myers\t"<<"CH7_EX6\t"<<"CH7_EX6.exe"<<endl;
        int randNum, choice, primeYesNo;
        srand (time(NULL));        
        randNum = rand() % 100;
        cout << "The two digit number is: " << randNum<<"\n"<< endl;

        do{
        cout << "Enter | "<< "Which does this to the number." << endl;
        cout << "  1   | "<< "double the number." << endl;
        cout << "  2   | "<< "reverse the digits." << endl; 
        cout << "  3   | "<< "raise the number to the power of 2, 3, or 4." << endl; 
        cout << "  4   | "<< "sum the digits." << endl; 
        cout << "  5   | "<< "raise the first digit to the power of second digit." << endl; 
        cout << "  6   | "<< "raise the first two digits to the power of the last digit." << endl; 
        cout << "  9   | "<< "Terminate the program." << endl;
        cout << "Choice: ";
        cin >> choice;
        cout<<endl;

        switch (choice){
        case 1:
                randNum = doubleNum(randNum);
                primeYesNo = primeNum(randNum);
                printFunction (randNum, primeYesNo);
                randNum = lessThanTen (randNum);
                break;
        case 2:
                randNum = revNum(randNum);
                primeYesNo = primeNum(randNum);
                printFunction (randNum, primeYesNo);
                randNum = lessThanTen (randNum);
                break;
        case 3:
                randNum = powNum(randNum);
                primeYesNo = primeNum(randNum);
                printFunction (randNum, primeYesNo);
                randNum = lessThanTen (randNum);
                break;
        case 4:
                randNum = sumNum(randNum);
                primeYesNo = primeNum(randNum);
                printFunction (randNum, primeYesNo);
                randNum = lessThanTen (randNum);
                break;
        case 5:
                randNum = firstToSecond(randNum);
                primeYesNo = primeNum(randNum);
                printFunction (randNum, primeYesNo);
                randNum = lessThanTen (randNum);
                break;
        case 6:
                randNum = firstTwoToLast(randNum);
                primeYesNo = primeNum(randNum);
                printFunction (randNum, primeYesNo);
                randNum = lessThanTen (randNum);
                break;
        default:
                break;
        system ("pause");
        }
}
        while (choice !=9);
        cout << endl;
        system ("pause");
        return 0;
}
int doubleNum(int randNum){
        randNum = randNum * 2;
        return randNum;
}
int revNum(int randNum){
        int ones = 0, tens = 0, huns = 0, thous = 0;
        if (randNum <10){
                return randNum;
        }
        if (randNum < 100){
                ones = randNum%10;
                randNum = randNum/10;
                tens = randNum%10;
                randNum = ones*10 + tens*1;
                return randNum;
        }
        if (randNum <1000){
                ones = randNum%10;
                randNum = randNum/10;
                tens = randNum%10;
                randNum = randNum/10;
                thous = randNum%10;
                randNum = ones*100 + tens*10 + thous*1;
                return randNum;
        }
        else;
                return 0;
}
int powNum(int randNum){
        double raiseTo;
        cout << endl << "Enter power (2, 3, or 4): ";
        cin >> raiseTo;
        while((raiseTo!=2)||(raiseTo!=3)||(raiseTo!=4)){
                cout<<"Only power 2,3, or 4 is allowed";
                cin>>raiseTo;
                cout<<endl;
        }
                randNum = pow(randNum, raiseTo);
                return randNum;            
}
int sumNum(int randNum){
        int ones, tens, huns, thous;
        ones = randNum%10;
        randNum = randNum/10;
        tens = randNum%10;
        randNum = randNum/10;
        huns = randNum%10;
        randNum = randNum/10;
        thous = randNum%10;

        randNum = ones + tens + huns + thous;

        return randNum;
}
int firstToSecond(int randNum){
        double ones, tens;        
        ones = randNum%10;
        randNum = randNum/10;
        tens = randNum%10;
        randNum = pow(tens, ones);
        return randNum;
}
int firstTwoToLast(int randNum){
        if (randNum <100 || randNum > 999){
                cout << endl;
                cout << "To perform this operation, it must be a three digit number." << endl;
                return randNum;
        }
        double ones, tens, huns;       
        ones = randNum%10;
        randNum = randNum/10; 
        tens = randNum%10;
        randNum = randNum/10;
        huns = randNum%10;
        randNum = pow(ones + tens*10, huns);
        return randNum;
}
int primeNum(int randNum){
        int primeYesNo;
        int count = 0;
        for (int i = 2; i < randNum; i++){
                if (randNum%i == 0){
                        count++;                        
                        break;
                }
        }
        if (count == 0){
                primeYesNo = 0;
                return primeYesNo;
        }
        else{
                primeYesNo = 1;
                return primeYesNo;
        }
}
void printFunction(int randNum, int primeYesNo){
                if (primeYesNo == 0){
                        cout << endl;
                        cout << randNum << " is prime." << endl << endl;
                }
                else{
                        cout << endl;
                        cout << randNum << " is not prime." << endl << endl;
                }
}
int lessThanTen (int randNum){
        if (randNum < 10){
                cout << randNum << " is less than 10, so adding 10 to it." << endl;
                randNum = randNum + 10;
                return randNum;
        }
        return randNum;
}