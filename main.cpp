#include <iostream>
#include <string>
#include <array>
#include "math-solver.h"

void clearcommand(void){
#if defined(_WIN32) || defined(_WIN64)
system("cls");
#elif __APPLE__ || __MACH__ || __linux__
system("clear");
#else
system("clear");
#endif              
}

using namespace std;

int reciver(string command)
{
    if (command == "help"){
        clearcommand();
        cout << "所有的命令： " << endl
             << "gcd - 最大公因數  area - 座標求面積  help - 顯示所有用法  exit/quit - 關閉這個程式" << endl;
    }

    else if (command == "gcd")
    {
        int nums[50] = {}, index=0;
        cout << "輸入數字, 用空格隔開: " ;
        while (cin>>nums[index]){
            if(cin.get() == '\n') break;
            index++;
        }
        
        cout << "最大公因數是： " << GCD(nums, index+1) << endl;
    }

    else if (command == "area")
    {
        float det[50][2];
        int index=0;
        cout << "輸入個點座標，(請依照順/逆時針輸入該點座標) 比如 (1, 2) (-1, 0) (0, 0)  \n就輸入 \"1 2 -1 0 0 0\"\n " ;
        while (cin>>det[index][0]>>det[index][1]){
            if (cin.get() == '\n') break;
            index++;
        }
        if (index < 2) {
            cout << "座標數必須大於兩個" << endl ;
            return 0;
        }
        det[index+1][0] = det[0][0];
        det[index+1][1] = det[0][1];
        cout << "面積是 " << abs(DET(det, index+2)/2) << endl;
    }

    else if (command == "exit" || command == "quit")
        return 1;

    else
        cout << "未知的命令!!" << endl ;

    return 0;
}

int main()
{
    string user_command;

    while (1)
    {

        cout << "你想要做什麼： " ;
        cin >> user_command ;

        if (reciver(user_command))
            return 0;

    }
    return 1;
}
