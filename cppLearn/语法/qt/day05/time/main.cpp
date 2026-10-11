#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d,e,f,g;
    cin>>a>>b>>c>>d;
    e=(c*60+d)-(a*60+b);
    f=e/60;
    g=e%60;
    cout<<f<<" "<<g;
    return 0;
}
