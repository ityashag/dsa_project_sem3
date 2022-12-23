#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
#include <conio.h>
//#include <time.h>
//#include <bits/stdc++.h>
#include "timerup.cpp"
#include "clc.cpp"
#include "maze.cpp"
#include "td.cpp"
using namespace std;
/*using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;*/
char frame[50][100];
class selection_screen
{
public:
    void first_screen(int selection)
    {
        for (int i = 0; i < 50; i++)
        {
            for (int j = 0; j < 100; j++)
            frame[i][j] = ' ';
            frame[11][22] = '@';
            frame[11][23] = '@';
            frame[11][24] = '@';
            frame[11][25] = '@';
            frame[11][26] = '@';
            frame[12][22] = '@';
            frame[13][22] = '@';
            frame[14][22] = '@';
            frame[15][22] = '@';
            frame[16][22] = '@';
            frame[17][22] = '@';
            frame[12][27] = '@';
            frame[13][27] = '@';
            frame[15][24] = '@';
            frame[14][23] = '@';
            frame[14][24] = '@';
            frame[14][25] = '@';
            frame[16][25] = '@';
            frame[17][26] = '@';

            frame[31][22] = '@';
            frame[31][23] = '@';
            frame[31][24] = '@';
            frame[31][25] = '@';
            frame[31][26] = '@';
            frame[31][27] = '@';
            frame[31][28] = '@';
            frame[32][26] = '@';
            frame[33][26] = '@';
            frame[34][26] = '@';
            frame[35][26] = '@';
            frame[36][26] = '@';
            frame[37][25] = '@';
            frame[37][24] = '@';
            frame[36][23] = '@';

            frame[31][61] = '@';
            frame[31][62] = '@';
            frame[31][63] = '@';
            frame[31][64] = '@';
            frame[31][65] = '@';
            frame[31][66] = '@';
            frame[31][67] = '@';
            frame[31][68] = '@';
            frame[31][69] = '@';

            frame[32][65] = '@';
            frame[33][65] = '@';
            frame[34][65] = '@';
            frame[35][65] = '@';
            frame[36][65] = '@';
            frame[37][65] = '@';


            frame[11][62] = '@';
            frame[11][63] = '@';
            frame[11][64] = '@';
            frame[11][65] = '@';

            frame[12][61] = '@';
            frame[13][61] = '@';
            frame[14][61] = '@';
            frame[15][61] = '@';
            frame[16][61] = '@';

            frame[17][62] = '@';
            frame[17][63] = '@';
            frame[17][64] = '@';
            frame[17][65] = '@';


            for (int i = 0; i < 10; i++)
                for (int j = 0; j < 20; j++)
                    if (i == 0 || j == 0 || i == 9 || j == 19)
                        frame[10 + ((selection) / 2) * 20 + i][20 + ((selection) % 2) * 40 + j] = char(219);
        }
    }
    void printer()
    {
        system("cls");
        cout<<"\t\t************************************************************\n\t\t\t\tPRODUCTIVITY INTERFACE\n\n\t\t************************************************************\n";
        for (int i = 10; i < 40; i++)
        {
            for (int j = 0; j < 100; j++)
                cout << frame[i][j];
            cout << endl;
        }
    }
    int main()
    {
        int input = 0;
        char a;
        while (true)
        {
            first_screen(input);
            system("cls");
            printer();
            a = getch();
            if (a == 'w'){
                if(input>1)
                    input -= 2;
            }
            else if (a == 's'){
                if(input<2)
                input += 2;
            }
            else if (a == 'a'){
                if(input%2>0)
                    input -= 1;
            }
            else if (a == 'd'){
                if(input%2<1)
                input += 1;
            }
            else if (a == ' ')
            {
                system("CLS");
                return input;
            }
            system("CLS");
        }
    }
};

int main()
{
    selection_screen ob1;
    while (true)
    {
        switch (ob1.main())
        {
        case 0:
            mainm();
            break;
        case 1:
            main3();
            break;
        case 2:
            maint();
            break;
        case 3:
            main1();
            break;
        }
    }
}
