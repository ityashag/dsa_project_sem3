#include <iostream>
#include <vector>
#include <fstream>
#include <conio.h>
#include <windows.h>
using namespace std;
class t
{
public:
    string task, deadline;
    void input()
    {
        cout << "Enter task name ";
        cin >> task;
        cout << "Enter task deadline ";
        cin >> deadline;
    }
};
void add()
{
    t temp;
    temp.input();
    fstream f1;
    f1.open("file.txt", ios::app);
    f1 << "\n"
       << temp.task << " " << temp.deadline << " N";
    f1.close();
}
void show()
{
    cout << "Sno.\tTask name \tTask deadline\tstatus\n";
    string s;
    fstream f2;
    f2.open("file.txt");
    int i = 1;
    while (!f2.eof())
    {
        f2 >> s;
        if (s.compare("\n")==0)
            break;
        cout << i++ << "\t ";
        cout << s << "\t\t";
        f2 >> s;
        cout << s << "\t\t";
        f2 >> s;
        if (s.compare("N") == 0)
            cout << "Not done";
        else if (s.compare("D") == 0)
            cout << "Done";
        cout << "\n";
    }
}
void del(int i)
{

    fstream f1;
    f1.open("file.txt");
    vector<string> ob;
    // int j=0;
    f1.seekg(0, ios::beg);
    while (f1)
    {
        string s, temp;
        f1 >> temp;
        s = s + temp + " ";
        f1 >> temp;
        s = s + temp + " ";
        f1 >> temp;
        s = s + temp + "\n";
        if (s.length() > 3)
            ob.push_back(s);
    }
    ob.erase(ob.begin() + i);
    f1.close();
    f1.open("file.txt", ios::out | ios::trunc);
    for (int k = 0; k < ob.size(); k++)
    {
        f1 << ob[k];
    }
    f1.close();
}
void edit()
{
    fstream f1;
    f1.open("file.txt");
    vector<string> ob;
    f1.seekg(0, ios::beg);
    while (f1)
    {
        string s, temp;
        f1 >> temp;
        s = s + temp + " ";
        f1 >> temp;
        s = s + temp + " ";
        f1 >> temp;
        s = s + temp + "\n";
        if (s.length() > 3)
            ob.push_back(s);
    }
    f1.close();
    cout << "Enter task no. to edit ";
    int op;
    cin >> op;
    system("cls");
    cout << "Enter 1 to edit task \n";
    cout << "Enter 2 to edit task status\n";
    int i;
    cin >> i;
    f1.open("file.txt");
    string s, temp;
    if (i == 1)
    {
        t temp;
        temp.input();
        s = temp.task + " " + temp.deadline + " " + "N" + "\n";
        ob[op - 1] = s;
        f1.close();
        f1.open("file.txt", ios::out | ios::trunc);
        // show();
        for (int k = 0; k < ob.size(); k++)
        {
            f1 << ob[k];
        }
        f1.close();
    }

    else if (i == 2)
    {
        f1.close();
        cout << "Enter 1 to mark as done ";
        cin >> s;
        //s="";
        if (s.compare("1") == 0)
        {
            s="";
            int ab=0,c=0;;
            while(c<2){
                if((ob[op - 1])[ab]==' ')
                    c++;
                s=s+(ob[op - 1])[ab++];
            }
            s=s+"D\n";
            Sleep(2);
            ob[op-1]=s;
            f1.open("file.txt", ios::out | ios::trunc);
            for (int k = 0; k < ob.size(); k++)
            {
                f1 << ob[k];
            }
            f1.close();
        }
    }
}
int maint()
{
    cout << "              *****************************************" << endl;
    cout << "              ||                                     ||" << endl;
    cout << "              || WELCOME TO YOUR DAILY TASK MANAGER  ||" << endl;
    cout << "              ||          WRITE THEM DOWN            ||" << endl;
    cout << "              ||          IMPLIMENT  THEM            ||" << endl;
    cout << "              ||             KEEP CALM               ||" << endl;
    cout << "              ||&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&||" << endl;
    cout << "              ||                                     ||" << endl;
    cout << "              *****************************************" << endl;
    cout << "======================= TO DO LIST =============================\n";
    cout << "================================================================\n";
    getch();
a:
    cout << "Enter 1 to add\n";
    cout << "Enter 2 to show\n";
    cout << "Enter 3 to delete\n";
    cout << "Enter 4 to edit\n";
    cout << "Enter 5 to exit\n";
    int input;
    cin >> input;
    system("cls");
    if (input == 1)
    {
        add();
    }
    else if (input == 2)
    {
        show();
    }
    else if (input == 3)
    {
        int a;
        cout << "Enter task number to delete ";
        cin >> a;
        del(a - 1);
    }
    else if (input == 4)
    {
        edit();
    }
    else if (input == 5)
        goto b;
    goto a;
b:
    return 0;
}