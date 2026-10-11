#include <iostream>

using namespace std;

int main() {
    int a = 10;
    int b = 10;

    const int * p1 = &a;
    p1=&b;
    //    *p1=100;


    int* const p2=&a;
//    p2=&b;
    *p2=100;
//    cout<<a<<endl;

    system("pause");
    return 0;
}
