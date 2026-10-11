#include <iostream>
#include <cstring>
using namespace std;
bool a[240][240];

void ex(int x1,int y1,int x2,int y2){
    for(int i=x1;i<=x2;i++)
        for(int j=y1;j<=y2;j++)
            a[i][j]=1;
}

int main()
{
    int zx,zy,m;//zx表示总行,zya表示总列,m表示指令个数
    int x1,y1,x2,y2,sum=0;//(x1,y1),(x2,y2)表示一个长方形左上角和右下角的坐标
    memset(a,0,sizeof(a));
    cin>>zx>>zy>>m;
    for(int i=0;i<m;i++){
        cin>>x1>>y1>>x2>>y2;
        ex(x1,y1,x2,y2);
    }
    for(int i=1;i<=zx;i++)
        for(int j=1;j<=zy;j++)
            if(a[i][j])
                sum++;
    //cout << "Hello World!" << endl;
    return 0;
}
