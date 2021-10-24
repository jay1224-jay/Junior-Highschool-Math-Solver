#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <array>
#include <string>
#include <cmath>
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

#define PI 3.14159265

using namespace std;

int reciver(string command)
{
    if (command == "help"){
        cout << "所有的命令： " << endl
             << " gcd        最大公因數 " << endl
             << " lcm        最小公倍數 " << endl 
             << " areap      座標求面積 " << endl 
             << " se         聯立方程式的解" << endl
             << " help       顯示所有用法 " << endl 
             << " sin        sin " << endl
             << " cos        cos " << endl
             << " tan        tan " << endl
             << " areas      get area from sides" << endl
             << " qe         Quadratic equation"  << endl
             << " exit/quit  關閉這個程式" << endl ;

    }

    else if (command == "gcd")
    {
        array<int, 50> nums;
        int index=0;
        cout << "輸入數字, 用空格隔開: " ;
        while (cin>>nums[index]){
            if(cin.get() == '\n') break;
            index++;
        }
        
        cout << "最大公因數是： " << GCD(nums, index+1) << endl;
    }

    else if (command == "lcm")
    {
        array<int, 50> nums;
        int index=0, answer=0;
        array<int, 50> gcd_array;
        cout << "輸入數字, 用空格隔開: " ;
        while (cin>>nums[index]){
            if(cin.get() == '\n') break;
            index++;
        } 
        gcd_array[0] = nums[0];
        gcd_array[1] = nums[1];
        answer = nums[0]*nums[1]/GCD(gcd_array, 2); 
        for (int i=2;i<index+1;i++){
            gcd_array[0] = answer; 
            gcd_array[1] = nums[i];  
            answer = gcd_array[0]*gcd_array[1]/GCD(gcd_array, 2);
        }
        cout << "最小公倍數是："  << answer << endl;

    }

    else if (command == "areap")
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

    else if (command == "se"){
        // 聯立方程式英文 simultaneous equations 
        cout <<         "你有一個聯立方程式："                      << endl 
             <<         "    2x + 3y = 80  "                        << endl 
             <<         "     x - 3y = -50  "                   << endl 
             << endl << "請輸入   "                             << endl 
             <<         " 2 3 80 (按一下Enter) "              << endl
             <<         " 1 -3 -50 (再按一下Enter) "            << endl 
             << endl << "須輸入 \"1\""            << endl 
             <<         "可以輸入小數點, 但分數不行" << endl ;
        
        /*
        EQUATION a;
        a.a = 10;
        a.b = 20;
        a.c = 30;
        cout << simultaneous_equations(a, a) << endl; 
        */

        EQUATION eq1, eq2;
        
        cin >> eq1.a >> eq1.b >>  eq1.c;  // ax+by=c

        /*
        if (stop) {
            cout << "\n注意：\n如果係數是 1 , 你仍須輸入 \"1\" \n請依照格式輸入,輸入前有教學\n" ;
            return 1;
        }
        */


        cin >> eq2.a >> eq2.b >> eq2.c ; // ax+by=c

        /*
        if (stop){
            cout << "\n注意：\n如果係數是 1 , 你仍須輸入 \"1\" \n請依照格式輸入,輸入前有教學\n" ;
            return 1;
        }
        */

        array<string, 2> answer = simultaneous_equations(eq1, eq2);
        cout << "x = " << answer[0] << " y = " << answer[1] << endl;

    }

    else if (command == "sin"){
        float angle;
        cout << "type angle" << endl;
        cin >> angle ;
        cout << "sin(" << angle << ") is " << sin(angle*PI/180) << endl;
    }
    else if (command == "cos"){
        float angle;
        cout << "type angle" << endl;
        cin >> angle ;
        cout << "cos(" << angle << ") is " << cos(angle*PI/180) << endl;
    }
    else if (command == "tan"){
        float angle;
        cout << "type angle" << endl;
        cin >> angle ;
        cout << "tan(" << angle << ") is " << tan(angle*PI/180) << endl;
    }

    else if (command == "areas"){
        float a, b, c;
        cout << "type 3 length of sides" << endl;
        cin >> a >> b >> c;
        cout << "area is " << heronFormula(a, b, c) << endl;
    }

    else if (command == "qe"){
        float a, b, c;
        array<float, 3> answer;
        cin >> a >> b >> c;
        

        answer = QuadraticEquation(a, b, c);

        if (answer[2]){
            for (int i=0;i<3;i++)
                cout << answer[i] << " ";
        }
        
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
        
        cout << endl ;
    }
    
    return 1;
}
