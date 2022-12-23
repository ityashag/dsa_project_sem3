#include <iostream>
#include <windows.h>
#include <chrono>
#include <thread>
#include <conio.h>
#include <thread>
#include <cstdio>
#include <ctime>
#include <vector>
using namespace std;

int input = 100;
char i = '0';
int ti=0;
bool flag=true;
bool flag2=false;
vector <int> laps;
void print_time(int time)
{
    cout << "\nIf you want to stop the timer press '1'\nif you want to add extra time by 1 minute press '2'\nif you want to reduce the time by 1 minute press '3'\n";
    cout << "\t\t\t\t\t\t\t" << time / 3600 << ":" << (time % 3600) / 60 << ":" << time % 60;
}
void timer()
{

    while (input + 1 > 0)
    {
        if (input == -1)
            return;
        system("CLS");
        print_time(input);
        cout << endl;

        Sleep(600);
        input--;
        if (input < 10&&input>=5)
        {
            Beep(8000, 400);

        }
        else if(input<5){
            Beep(7000,200);
            Beep(7000,200);
        }
        else
            Sleep(400);
    }
    if (input == -1)
        cout << "timer has run out press 4 to continue or 5 to make a new timer";
    
    return;
}
void print_t(int ti){
    cout<<ti/3600<<":"<<(ti%3600)/60<<":"<<ti%60<<"\n";
}
void stop(){
    while(flag){
        system("CLS");
        cout<<"1 to stop \n2 to pause \n3 to lap  \n4 to reset\n";
        print_t(ti);
        cout<<"\n\n\n";
        if(laps.size()>0){
            for(int i=0;i<laps.size();i++){
                print_t(laps[i]);
            }
        }
        while(flag2){
            Sleep(100);
        }
        ti+=1;
        Sleep(950);
        
    }
}
void stopwatch(){
    system("CLS");
    ti=0;
    cout<<"Enter 1 to start the stop watch\n2 to go back";
    i=getch();
    if(i!='1')
        return;
    system("CLS");
    std:: thread t1(stop);
    cout<<"1 to stop \n2 to pause \n3 to lap  \n4 to reset";
    a:
    i=getch();
    switch(i){
        case '1':
            flag=false;
            print_t(ti);
        break;
        case '2':
            flag2=true;
            Sleep(1000);
            cout<<"Enter 1 to resume";
            i=getch();
            if(i=='1'){
                flag2=false;
                goto a;
            }
        break;
        case '3':
            laps.push_back(ti);
            goto a;
        break;
        case '4':
            ti=0;
            laps.clear();
            goto a;
        default:
            flag=false;

    }
    ti=0;
    t1.join();
    cout<<"\nEnter any key to go to start screen";
    i=getch();
}
int timerr()
{
b:
    int time = 0;
    cout << "you will have 4 inbuilt timer options:" << endl;
    cout << "If you want to stop the timer press '1'\nif you want to add extra time by 1 minute press '2'\nif you want to reduce the time by 1 minute press '3'\n";
    cout << "1 for brush teeth:00:02:00\n2 for face mask: 00:15:00\n3 for boil eggs: 00:10:00\n4 for custom timer \n";
    int n;
    cin >> n;
    thread t;
    string x;

    // try
    //{
    switch (n)
    {
    case 1:
        cout << "brush teeth\n";
        input = 120;
        // cout<<"\t"<<input;
        t = thread(timer);
        break;
    case 2:
        cout << "face mask\n";
        input = 900;
        t = thread(timer);
        break;
    case 3:
        cout << "boil eggs\n";
        input = 600;
        t = thread(timer);
        break;
    case 4:
        // string x;
        cout << "enter the name of custom timer: ";
        fflush(stdin);
        cin >> x;
        fflush(stdin);
        int h, m, s;
        cout << "Enter timer in hours minutes and seconds :\n";
        cin >> h >> m >> s;
        try
        {
            if (m > 60)
            {
                throw 1;
            }
        }
        catch (int x)
        {
            cout << "minutes cannot be  greater than 60 minutes, exception run" << endl;
        }
        try
        {
            if (s > 60)
            {
                throw 1;
            }
        }
        catch (int x)
        {
            cout << "seconds canot be  greater than 60 seconds, exception run" << endl;
        }

        input = h * 3600 + m * 60 + s;
        t = thread(timer);
        cout << "herer";
        break;
    default:
        cout << "please enter right operation";
    }
a:
    char i = getch();
    if (i == '1')
    {
        cout << "ok the timer has been stopped";
        input = -2;
        t.join();
        return 0;
    }
    else if (i == '2')
    {
        input += 60;
        goto a;
    }
    else if (i == '3')
    {
        if (input <= 60)

        {
            system("CLS");
            cout << "0:0:0";
            cout << "\ntimer has been run out";
            input = 0;
            t.detach();
            return 0;
        }
        input -= 60;
        goto a;
    }
    else if (i == '4' && input != -1)
    {
        cout << "timer has run out";
    }
    else if (i == '5')
    {
        t.detach();
        system("cls");
        fflush(stdin);
        goto b;
    }
    // cout << "timer has run out";
    t.join();
    return 0;
}
int main1(){
    a:
    system("CLS");
    cout<<"Enter 1 for timer and \n2 for stopwatch and \n3 to exit";
    char inp;
    inp=getch();
    switch(inp){
        case '1':
            timerr();
            goto a;
        break;
        case '2':
            stopwatch();
            goto a;
        break;
        case '3':
        break;
        default:
            cout<<"Enter correct option";
            Sleep(500);
            system("CLS");
            goto a;
    }
    return 0;
}