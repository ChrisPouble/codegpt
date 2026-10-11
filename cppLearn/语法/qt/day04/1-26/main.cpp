#include <iostream>

using namespace std;

void cat(int &x,int &y){
    int temp;
    temp=x;
    x=y;
    y=temp;
    cout <<"jiaohuanzhong  "<<x<<"\t"<<y<<endl;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<endl;
    cout <<"jiaohuanqian  "<<a<<"\t"<<b<<endl;
    cat(a,b);
    cout <<"jiaohuanhou  "<<a<<"\t"<<b<<endl;
    return 0;
}
