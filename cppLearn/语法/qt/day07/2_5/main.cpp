#include <iostream>

using namespace std;

int main() {

    int sh=100;
    do{

        int a=sh/100;
        int b=sh/10%10;
        int c=sh%10;
        if(a*a*a+b*b*b+c*c*c==sh){
            cout<<sh<<endl;
            sh++;
        }
        else sh++;

    }while(sh<=999);
    system("pause");
    return 0;
}
