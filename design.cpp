#include<iostream>
using namespace std;

void phone()
{
    int n=20;
    int m=27;
    char ph[n][m];
    for(int i=0;i<n;i++)
    {
        if(i==0){ph[i][0]=char(244); ph[i][1]=char(244);}
        else {ph[i][0]='|'; ph[i][1]='|';}
        int j;
        for( j=2;j<m-2;j++)
        {
            if(i==0 || i==19) ph[i][j]='=';
            else ph[i][j]=' ';
        }
        if((i==n-1 && j==m-2) ){ph[i][j]=char(245); ph[i][j+1]=char(245); }
        else {ph[i][j]='|'; ph[i][j+1]='|';} 
    }

    //27-4=23char
    // dynamic eyelid
    //7 20
    // for(int j=7;j<=20;j++)
    // {
    //     ph[1][j]=char()
    // }

    ph[1][7+3]=char(243);
    ph[1][7+4]=char(242);
    ph[1][7+5]=char(241);
    ph[1][7+6]=char(246);
    ph[1][7+7]=char(247);




    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
           cout<<ph[i][j];
        }
        cout<<endl;
    }


}

int main()
{
    phone();
    // for(int i=0;i<255;i++)
    // {
    //     cout<<char(i)<<" ";
    // }
    // cout<<
    // ⌠⌠  ⌡⌡
    // ||


}