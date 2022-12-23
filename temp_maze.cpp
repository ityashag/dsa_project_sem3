/*
0 0 0 0 0 0 X 0 0 0  // 
0 X X X X 0 X 0 X 0  //
0 X 0 0 0 0 X 0 X 0  //
0 X 0 0 X 0 0 0 X 0  //
0 X 0 0 0 0 0 X X 0  //
0 X 0 0 0 0 0 0 0 0  //
0 X 0 0 0 0 0 0 0 0  //
0 X X X X 0 X 0 0 0  //
0 X 0 0 0 0 X 0 0 0  //
0 0 0 0 0 0 X 0 0 0  

*/

#include <iostream>
using namespace std;
int main(){
    int arr[10][10]={0};
    arr[0][6]=1;
    arr[1][1]=1;arr[1][2]=1;arr[1][3]=1;arr[1][4]=1;arr[1][6]=1;arr[1][9]=1;
    arr[2][1]=1;arr[2][6]=1;arr[2][9]=1;
    arr[3][1]=1;arr[3][4]=1;arr[3][9]=1;
    arr[4][1]=1;arr[4][7];arr[4][8]=1;arr[4][9]=1;
    arr[5][1]=1;
    arr[6][1]=1;
    arr[7][1]=1;arr[7][2]=1;arr[7][3]=1;arr[7][4]=1;
    arr[8][1]=1;arr[8][6]=1;
    arr[9][6]=1;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(arr[i][j]==1)
                cout<<"X";
            else 
                cout<<".";
        }
        cout<<"\n";
    }    
}