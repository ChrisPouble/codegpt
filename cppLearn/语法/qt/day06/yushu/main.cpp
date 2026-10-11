#include<iostream>
using namespace std;
int main(){
    int k,a1,a2,a3;
    bool sum=0;
    cin>>k;
    for(int i=10000;i<=30000;i++){
            a1=i/100;
            a2=(i/10)%1000;
            a3=i%1000;
            if(a1%k==0&&a2%k==0&&a3%k==0){
              sum=1;
              cout<<i<<endl;
            }
    }
    if(!sum)
        cout<<"No"<<endl;
    return 0;
}
