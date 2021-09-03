#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        cout << "type \n";
        cout << "a = " << a << "\t b = " << b << endl;
        if (cin.get() == '\n') break;
    }
    return 1;
}
