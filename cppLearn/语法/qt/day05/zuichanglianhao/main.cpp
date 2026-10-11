#include <iostream>

using namespace std;
int a[10000];
int main()
{
    int n,many=1,max=1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]+1==a[i+1])
        {
          many++;
          if(max<many)
              max=many;
        }
        else
        many=1;
    }
    cout<<max<<endl;
    return 0;
}
