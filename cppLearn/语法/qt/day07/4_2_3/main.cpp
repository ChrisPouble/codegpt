#include <iostream>

using namespace std;

int main()
{
    for(int i=1;i<=100;i++){
        if(i/10==7)
            cout<<"da xiao bao"<<endl;
        else if (i%10==7) {
            cout<<"da xiao bao"<<endl;
        }
        else if (i%7==0) {
            cout<<"da xiao bao"<<endl;
        }
        else {
            cout<<i<<endl;
        }
    }

    return 0;
}
