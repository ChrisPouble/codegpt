#include <iostream>
using namespace std;
int main()
{
    int a[10];
    int sum=0,c;//c表示淘淘手能伸到的最高高度
    for(int i=0;i<10;i++){
        cin>>a[i];
    }
    cin>>c;
    for(int i=0;i<10;i++){
        if(c+30-a[i]>=0)
            sum++;
    }
    cout<<sum;
    return 0;
}
