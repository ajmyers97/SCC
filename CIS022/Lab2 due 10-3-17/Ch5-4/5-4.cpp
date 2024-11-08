//* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
//* Program name    : CH5_EX4                                          * 
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
#include <string>
using namespace std;


int main(){
    cout<<"Allen Myers\t"<<"CH5_EX4\t"<<"CH5_EX4.exe"<<endl;
    int counter;
    char phoneNumber,startOrEnd,repeat;
    cout<<"Enter Y/y to convert a telephone number from letters to digits."<<endl;
    cout<<"Enter any other letter to terminate the program."<<endl;
    cin>>startOrEnd;

    while((startOrEnd=='Y') || (startOrEnd=='y')){
       cout << "Enter a telephone number using letters:" 
         << endl;
    
    for(counter = 0; counter < 7; counter ++){
     cin >> phoneNumber;
     
      if(counter == 3)
         cout << "-";
     
     if((phoneNumber >= 'A' && phoneNumber <= 'Z') || (phoneNumber >= 'a' && phoneNumber <= 'z'))
     switch(phoneNumber){
         case 'A':
         case 'a':
         case 'B':
         case 'b':
         case 'C':
         case 'c':
             cout << 2;
             break;
         case 'D':
         case 'd':
         case 'E':
         case 'e':
         case 'F':
         case 'f':
             cout << 3;
             break;
         case 'G':
         case 'g':
         case 'H':
         case 'h':
         case 'I':
         case 'i':
             cout << 4;
             break;
             
         case 'J':
         case 'j':
         case 'K':
         case 'k':
         case 'L':
         case 'l':
             cout << 5;
             break;
         case 'M':
         case 'm':
         case 'N':
         case 'n':
         case 'O':
         case 'o':
             cout << 6;
             break;
         case 'P':
         case 'p':
         case 'Q':
         case 'q':
         case 'R':
         case 'r':
         case 'S':
         case 's':
             cout << 7;
             break;
             
         case 'T':
         case 't':
         case 'U':
         case 'u':
         case 'V':
         case 'v':
             cout << 8;
             break;
             
         case 'W':
         case 'w':
         case 'X':
         case 'x':
         case 'Y':
         case 'y':
         case 'Z':
         case 'z':
             cout << 9;
             break;             
}
}
cout<<endl;
cout<<"Enter Y/y to process another telephone number."<<endl;
cout<<"Enter any other letter to terminate the program."<<endl;
cin>>startOrEnd;
}
}