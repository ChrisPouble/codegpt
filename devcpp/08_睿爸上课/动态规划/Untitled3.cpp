#include <bits/stdc++.h>
using namespace std;
int s[5];
bool f[1300];
int a[21];
int main() 
{
    for(int i = 1;i<=4;i++)
    cin>>s[i];
    int ans=0;
    for(int _i=1;_i<=4;_i++)
    {
        memset(f,0,sizeof(f));
        int sum=0;
        for(int i=1;i<=s[_i];i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        f[0]=1;
        for(int i=1;i<=s[_i];i++)
        {
            for(int j=sum;j>=0;j--)
            {
                if(f[j]==1)
                {
                    f[j+a[i]]=1;
                }
            }
        }
        for(int i=(sum+1)/2;i<=sum;i++)
        if(f[i]==1)
        {
            ans+=i;
            break;
        }
    } 
    cout<<ans<<endl;   
    return 0;
}
/**************************************************************
5 4 3 2
15 12 10 8 7
6 11 14 13
9 5 10
20 15
****************************************************************/
