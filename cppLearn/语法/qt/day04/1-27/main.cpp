#include <iostream>

using namespace std;

void change(int &a ){
    a=a+1;
    cout<<a<<endl;
}

int main()
{
    int b=3;
    change(b);
    cout<<b<<endl;
    return 0;
}
