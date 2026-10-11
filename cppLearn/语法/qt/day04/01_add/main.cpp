#include <iostream>

using namespace std;

int add(int a ,int b){
    return a+b;
}

int main()
{
    int n,a,b;
    cin>>n;
    int C[n];

    for (int i=0;i<n;i++) {
        cin>>a>>b;
        C[i]=add(a,b);
    }

    for (int i=0;i<n;i++) {
        cout<<C[i]<<endl;
    }

    return 0;
}
