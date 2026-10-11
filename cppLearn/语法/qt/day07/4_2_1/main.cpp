#include <iostream>

using namespace std;
#include<ctime>

int main()
{
    srand((unsigned int)time(NULL));
    int num=rand()%100+1;

    int val;
    int i=1;
    while(i<=7){
        cin>>val;
        if(val>num){
            cout<<"big"<<endl;
            i++;
        }
        else if(val<num){
            cout<<"small"<<endl;
            i++;
        }
        else {
            cout<<"niu"<<endl;
            break;
        }
    }
    if(i==8){
        cout<<"ni mei le"<<endl;
    }

    return 0;
}
