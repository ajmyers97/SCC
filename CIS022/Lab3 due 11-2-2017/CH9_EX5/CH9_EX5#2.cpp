#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct MenuItem{
   string description;
   double price;
   int quantity;
};
const int MAX_ITEMS = 20;
const double TAX_RATE = 0.05;

void getData(MenuItem menuList[], int &size);
void showMenu(MenuItem menuList[], int size);
void printCheck(MenuItem menuList[], int size);

int main(){
  cout<<"Allen Myers\t"<<"CH9_EX5\t"<<"CH9_EX5.exe"<<endl;
   MenuItem menuList[MAX_ITEMS];
   int size = 0;
   getData(menuList, size);
   showMenu(menuList, size);
   printCheck(menuList, size);
   system("pause");
   return 0;
}
void getData(MenuItem menuList[], int &size){
  ifstream inData;
  ofstream outData;
  inData.open("Ch9_Ex5_Data.txt");
  //I was not familiar with exactly how to implement the inData function to pull
  //the data from the required file. The program compiles and runs properly without the 
  //indata function.
   menuList[0].description = "Plain Egg";
   menuList[0].price = 1.45;
   menuList[0].quantity = 0;

   menuList[1].description = "Bacon and Egg";
   menuList[1].price = 2.45;
   menuList[1].quantity = 0;

   menuList[2].description = "Muffin";
   menuList[2].price = 0.99;
   menuList[2].quantity = 0;

   menuList[3].description = "French Toast";
   menuList[3].price = 1.99;
   menuList[3].quantity = 0;

   menuList[4].description = "Fruit Basket";
   menuList[4].price = 2.49;
   menuList[4].quantity = 0;

   menuList[5].description = "Cereal";
   menuList[5].price = 0.69;
   menuList[5].quantity = 0;

   menuList[6].description = "Coffee";
   menuList[6].price = 0.50;
   menuList[6].quantity = 0;

   menuList[7].description = "Tea";
   menuList[7].price = 0.75;
   menuList[7].quantity = 0;

   size = 8;
}
// This function shows the different items offered by the restaurant and
// tells the user how to select the items.
void showMenu(MenuItem menuList[], int size){
   cout << "Welcome to Johnny's Restaurant" << endl;
   cout << "----------MENU ITEMS----------" << endl;
   for (int i = 0; i < size; i++){
       cout << (i + 1) << ". " << left << setw(21) << menuList[i].description << "$" << setw(6) << setprecision(2) << fixed << menuList[i].price << endl;
   }
   cout << "------------------------------" << endl;

   int num=0, orderNum=0;
   int qty=0;
   char repeatYN;
  
   cout << "\nEnter item number (1-8) (-1 for exit): ";
   cin >> num;

   while (num != -1){
       cout << "Enter item number (1-8) (-1 for exit): ";
       cin >> num;
       cout<<"How many orders?:";
       cin>>orderNum;
       if (num >= 1 && num <= 8){
           menuList[num - 1].quantity = orderNum;
       }
   }
}
void printCheck(MenuItem menuList[], int size){
   double totalPrice = 0;
   double taxAmount = 0;
  
   cout << "\nYour Bill..." << endl;
   cout << endl << "Welcome to Johnny's Restaurant" << endl;
   for (int i = 0; i < size; i++){
       if (menuList[i].quantity > 0){
           cout << left << setw(20) << menuList[i].description << "$" << setw(10) << setprecision(2) << fixed << menuList[i].price << endl;
           totalPrice += menuList[i].price;
       }
   }
   taxAmount = totalPrice * TAX_RATE;
   cout << setw(20) << "Tax:"<< "$" << setw(10) << setprecision(2) << fixed << taxAmount << endl;
   cout << setw(20) << "Amount Due:" << "$" << setw(10) << setprecision(2) << fixed << (totalPrice + taxAmount) << endl << endl;
}