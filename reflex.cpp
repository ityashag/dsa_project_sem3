#include <iostream>
//#include <stdlib.h>
#include <windows.h>
#include <chrono>
//#include <thread>
#include <conio.h>
//#include <time.h>
#include <unistd.h>
using namespace std;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::seconds;
using std::chrono::system_clock;
//char frame[50][100];
char random(){
    return (char)(97+rand()/1310);
}
void print(char a){
    if(a=='a'){
        cout<<"      @      \n";
        cout<<"     @ @     \n";
        cout<<"    @   @    \n";
        cout<<"   @@@@@@@   \n";
        cout<<"  @       @  \n";
        cout<<" @         @ \n";
        cout<<"@           @\n";
    }
    else if(a=='b'){
        cout<<"@@@@@       \n";
        cout<<"@    @      \n";
        cout<<"@    @      \n";
        cout<<"@@@@@       \n";
        cout<<"@    @      \n";
        cout<<"@    @      \n";
        cout<<"@@@@@       \n";
    }
    else if(a=='c'){
        cout<<" @@@@@   \n";
        cout<<"@        \n";
        cout<<"@        \n";
        cout<<"@        \n";
        cout<<"@        \n";
        cout<<"@        \n";
        cout<<"@        \n";
        cout<<" @@@@@   \n";
    }
    else if(a=='d'){
        cout<<"@@@@@@   \n";
        cout<<"@     @   \n";
        cout<<"@     @   \n";
        cout<<"@     @   \n";
        cout<<"@     @   \n";
        cout<<"@     @  \n";
        cout<<"@     @   \n";
        cout<<"@@@@@@   \n";
    }
    else if(a=='e'){
        cout<<"@@@@@@   \n";
        cout<<"@        \n";
        cout<<"@        \n";
        cout<<"@@@@@@    \n";
        cout<<"@        \n";
        cout<<"@       \n";
        cout<<"@        \n";
        cout<<"@@@@@@   \n";
    }
    else if(a=='f'){
        cout<<"@@@@@@   \n";
        cout<<"@        \n";
        cout<<"@        \n";
        cout<<"@@@@@@    \n";
        cout<<"@        \n";
        cout<<"@       \n";
        cout<<"@        \n";
        cout<<"@   \n";
    }
    else if(a=='g'){
        cout<<" @@@@@   \n";
        cout<<"@     @   \n";
        cout<<"@        \n";
        cout<<"@        \n";
        cout<<"@   @@@   \n";
        cout<<"@     @  \n";
        cout<<"@     @   \n";
        cout<<" @@@@@   \n";
    }
    else if(a=='h'){
        cout<<"@    @   \n";
        cout<<"@    @    \n";
        cout<<"@    @    \n";
        cout<<"@@@@@@    \n";
        cout<<"@    @    \n";
        cout<<"@    @   \n";
        cout<<"@    @    \n";
        cout<<"@    @   \n";
    }
    else if(a=='i'){
        cout<<"@@@@@@@   \n";
        cout<<"   @     \n";
        cout<<"   @     \n";
        cout<<"   @    \n";
        cout<<"   @     \n";
        cout<<"   @    \n";
        cout<<"   @     \n";
        cout<<"@@@@@@@   \n";
    }
    else if(a=='j'){
        cout<<"@@@@@@@   \n";
        cout<<"    @    \n";
        cout<<"    @    \n";
        cout<<"    @    \n";
        cout<<"    @    \n";
        cout<<" @  @   \n";
        cout<<"  @@     \n";
        cout<<"       \n";
    }
    else if(a=='k'){
        cout<<"@   @   \n";
        cout<<"@  @      \n";
        cout<<"@ @       \n";
        cout<<"@@    \n";
        cout<<"@ @       \n";
        cout<<"@  @     \n";
        cout<<"@   @     \n";
        cout<<"@    @   \n";
    }
    else if(a=='l'){
        cout<<"@       \n";
        cout<<"@        \n";
        cout<<"@        \n";
        cout<<"@    \n";
        cout<<"@        \n";
        cout<<"@       \n";
        cout<<"@        \n";
        cout<<"@@@@@@@   \n";
    }
    else if(a=='m'){
        cout<<"@@     @@   \n";
        cout<<"@ @   @ @    \n";
        cout<<"@  @ @  @    \n";
        cout<<"@   @   @    \n";
        cout<<"@       @    \n";
        cout<<"@       @   \n";
        cout<<"@       @    \n";
        cout<<"@       @   \n";
    }
    else if(a=='n'){
        cout<<"@@       @   \n";
        cout<<"@ @      @    \n";
        cout<<"@  @     @    \n";
        cout<<"@   @    @    \n";
        cout<<"@    @   @    \n";
        cout<<"@     @  @   \n";
        cout<<"@      @ @    \n";
        cout<<"@       @@   \n";
    }
    else if(a=='o'){
        cout<<" @@@@@@@       \n";
        cout<<"@       @    \n";
        cout<<"@       @    \n";
        cout<<"@       @    \n";
        cout<<"@       @    \n";
        cout<<"@       @   \n";
        cout<<"@       @    \n";
        cout<<" @@@@@@@   \n";
    }
    else if(a=='p'){
        cout<<"@@@@@   \n";
        cout<<"@    @    \n";
        cout<<"@    @    \n";
        cout<<"@@@@@    \n";
        cout<<"@        \n";
        cout<<"@       \n";
        cout<<"@        \n";
        cout<<"@       \n";
    }
    else if(a=='q'){
        cout<<" @@@@@@@       \n";
        cout<<"@       @    \n";
        cout<<"@       @    \n";
        cout<<"@       @    \n";
        cout<<"@       @    \n";
        cout<<"@   @   @   \n";
        cout<<"@    @  @    \n";
        cout<<" @@@@@@@   \n";
    }
    else if(a=='r'){
        cout<<"@@@@@   \n";
        cout<<"@    @    \n";
        cout<<"@    @    \n";
        cout<<"@@@@@    \n";
        cout<<"@@        \n";
        cout<<"@ @      \n";
        cout<<"@  @      \n";
        cout<<"@   @    \n";
    }
    else if(a=='s'){
        cout<<" @@@@@@@       \n";
        cout<<"@           \n";
        cout<<"@           \n";
        cout<<" @@@@@@@          \n";
        cout<<"        @    \n";
        cout<<"        @   \n";
        cout<<"        @    \n";
        cout<<" @@@@@@@   \n";
    }
    else if(a=='t'){
        cout<<"@@@@@@@   \n";
        cout<<"   @     \n";
        cout<<"   @     \n";
        cout<<"   @    \n";
        cout<<"   @     \n";
        cout<<"   @    \n";
        cout<<"   @     \n";
        cout<<"   @   \n";
    }
    else if(a=='u'){
        cout<<"@       @ \n";
        cout<<"@       @    \n";
        cout<<"@       @    \n";
        cout<<"@       @    \n";
        cout<<"@       @    \n";
        cout<<"@       @   \n";
        cout<<"@       @    \n";
        cout<<" @@@@@@@   \n";
    }
    else if(a=='v'){
        cout<<"@           @\n";
        cout<<" @         @ \n";
        cout<<"  @       @  \n";
        cout<<"   @     @   \n";
        cout<<"    @   @    \n";
        cout<<"     @ @     \n";
        cout<<"      @     \n";
        cout<<"           \n";
    }
    else if(a=='w'){

        cout<<"@           @ \n";
        cout<<"@           @ \n";
        cout<<" @         @  \n";
        cout<<" @    @    @  \n";
        cout<<"  @  @ @  @   \n";
        cout<<"  @ @   @ @   \n";
        cout<<"   @     @    \n";
        cout<<"              \n";
    }
    else if(a=='x'){
            cout<<"@           @\n";
        cout<<" @    @      \n";
        cout<<"  @  @       \n";
        cout<<"   @@       \n";
        cout<<"   @@       \n";
        cout<<"  @  @      \n";
        cout<<" @    @     \n";
        cout<<"@      @    \n";
    }
    else if(a=='y'){
        cout<<"    @      @\n";
        cout<<"     @    @ \n";
        cout<<"      @  @  \n";
        cout<<"       @@   \n";
        cout<<"       @    \n";
        cout<<"      @     \n";
        cout<<"     @      \n";
        cout<<"    @       \n";
    }
    else if(a=='z'){
        cout<<"  @@@@@@@@  \n";
        cout<<"        @   \n";
        cout<<"       @    \n";
        cout<<"      @      \n";
        cout<<"     @      \n";
        cout<<"    @       \n";
        cout<<"   @       \n";
        cout<<"  @@@@@@@@@ \n";
    }

}
int mainr(){
    srand(time(0));
    char ch,ch2;
    int time=0,score=0;
    cout<<"Press a key when ready\n";
    getch();
    sleep(1);
    cout<<"start\n";
    int flag=1;
    while(flag){
        system("CLS");
        ch=random();
        //cout<<ch<<"\n";
        print(ch);
        time = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        ch2=getch();
        time-=duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        time=-time;
        if(time>2000||ch!=ch2){
            flag=0;
            break;
        }
        else{
            score++;
            continue;
        }

    }
    cout<<"\nScore is "<<score;
    getch();
    return 0;
}
