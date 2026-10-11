#include <iostream>

using namespace std;

int main()
{
    int a =5;
    int *p= &a;
    int& b= a;
    int c =a;
    cout << c << endl;
    cout << a << endl;
    c=6;
    cout << c << endl;
    cout << a << endl;
    b=7;
    cout << b << endl;
    cout << a << endl;

    cout << p << endl;
    cout << *p << endl;

    return 0;
}
