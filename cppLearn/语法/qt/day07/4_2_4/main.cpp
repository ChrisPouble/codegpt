#include <iostream>

using namespace std;

int main() {
    //外层循环执行1次，内层循环执行1轮
    for (int i = 1; i <=9; i++)
    {
        for (int j = 1; j <=i; j++)
        {
            cout <<j<< "*" << i<<"="<<i*j<<" ";
        }
        cout << endl;
        cout << endl;
    }
    system("pause");
    return 0;
}
