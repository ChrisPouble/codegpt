#include <iostream>

using namespace std;

//int main()
//{
//        float s;
//        float sum=0;
//        cin>>s;

//        int count=0;

//        for(float i=2.0;sum<s;i*=0.98){
//            sum+=i;
//            count++;
//        }

//        cout<<count;

//        return 0;
//}

#include <math.h>

int main(){
    float s;
    float count=0;
    cin>>s;

    count=ceil(log(1-s/100.0)/log(0.98));

    cout<<count;

    return 0;
}


