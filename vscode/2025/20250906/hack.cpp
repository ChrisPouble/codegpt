#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("set.in","w",stdout);
    puts("10");
    for(int i=1;i<=10;i++){
        puts("100000 44");
        for(int j=1;j<=100000;j++)
            printf("%d ",(j-1)%44+1);
        puts("");
        for(int j=1;j<=44;j++)
            printf("100000 ");
        puts("\n1\n1");
    }
    return 0;
}