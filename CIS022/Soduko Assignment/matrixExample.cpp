#include <iostream>
#include<iomanip>
#include <cstdlib>

using namespace std;

const int rows=9;
const int columns=9;
int main(){
    int matrix[rows][columns];
    for(int i=1;i<10;i++)
        for(int j=1;j<10;j++)
            matrix[i][j]=rand()%9;
       //need a function to make sure the numbers don't repeat.
        
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++)
            cout<<matrix[i][j]<<' ';
        cout<<endl;
    }

}

