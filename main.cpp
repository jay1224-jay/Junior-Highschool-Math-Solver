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
             << "gcd - 最大公因數  help - 顯示所有用法 " << endl;
    }

    else if (command == "gcd")
    {
        int nums[50] = {}, index=0;
        cout << "輸入數字: " ;
        while (cin>>nums[index]){
            if(cin.get() == '\n') break;
            index++;
        }
        
        cout << GCD(nums, index+1) << endl;
        //cout << "最大公因數： " << GCD(MAX(a, b), MIN(a, b)) << endl;
    }

    else if (command == "line")
    {
        char left, right;
        float det[50][2];
        int index=0;
        while (cin>>left>>det[index][0]>>det[index][1]>>right){
            if (cin.get() == '\n') break;
            index++;
        }
        cout << "det is -> " << DET(det, index+1) << endl;
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
