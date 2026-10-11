#include <iostream>
using namespace std;
const int n = 6;
void test01(int arr[][n], int  n )
{
    int starx = 0, stary = 0;
    int loop = n / 2; //循环几圈
    int mid = n / 2; //矩阵中间位置
    int count = 1; 
    int offset = 1;
    int i, j;

    while(loop--)
    {
        i = starx;
        j = stary;

        for(j = stary; j < stary + n - offset; j++)
        {
            arr[starx][j] = count++;
        }
        for(i = starx; i < starx + n - offset; i++)
        {
            arr[i][j] = count++;
        }
        for(; j > stary; j--)
        {
            arr[i][j] = count++;
        }
        for(; i > starx; i--)
        {
            arr[i][j] = count++;
        }

        starx++;
        stary++;

        offset += 2;
    }

    if(n/2 == 1)
    {
        arr[mid][mid] = count++;
    }

    for(int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            cout << arr[a][b] << " ";
        }
        cout << endl;
    }

}

//int main()
//{
//    
//    int arr[n][n];
//    
//    test01(arr, n);
//
//    system("pause");
//    return 1;
//}