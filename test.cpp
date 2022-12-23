#include <iostream>
#include <conio.h>
#include <windows.h>
#include <thread>
#include <unistd.h>
#include <chrono>
#include <ctime>
#include <dos.h>
int ti=0;
int flag=0;
using namespace std;

void print_t(int ti){
    cout<<ti/3600<<":"<<(ti%3600)/60<<":"<<ti%60<<"\n";
}
void stop(){
    while(flag==0){
        print_t(ti);
        ti+=1;
        Sleep(1000);
        system("CLS");
    }
}
void stopwatch(){
    char i=0;
    ti=0;
    cout<<"1 to lap 2 to pause 3 to start stop 4 to reset";
    thread t1;
    t1=thread(stop);
    i=getch();
    flag=1;
        t1.join();
        print_t(ti);
    //t1.join();

}
int main(){
    stopwatch();
}