#include <iostream>

using namespace std;
void f1(){
    cout << "this is test01" << endl;
}
void s2(int a){
    cout << "this is test02" << endl;
    cout << "a = " << a << endl;
}
int t3(){
    cout << "this is test03 " << endl;
    return 0;
}
int f4(int a,int b){
    cout << "this is test04 " << endl;
    int sum = a + b;
    return sum;
    }

int main()
{
    f1();
    int a=1;s2(a);
    t3();
    int b=2;
    f4(a,b);
    return 0;
}
