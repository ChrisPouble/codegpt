#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generateMartrix(vector<vector<int>> arr, int n)
{
    //二维vector初始化方法,如果不给初始值就默认为0
    arr.resize(n,vector<int>(n) );

    int starx = 0, stary = 0;
    int loop = n / 2; //要转多少圈
    int offset = 1;
    int mid = n / 2; //为中间的元素赋值
    int count = 1;
    int i, j;

    while (loop--)
    {
        i = starx;
        j = stary;

        for (j = stary; j < n + stary - offset; j++)
        {
            arr[starx][j] = count++;
        }

        for (i = starx; i < n + starx - offset; i++)
        {
            arr[i][j] = count++;
        }

        for (; j > stary; j--)
        {
            arr[i][j] = count++;
        }

        for (; i > starx; i--)
        {
            arr[i][j] = count++;
        }

        starx++;
        stary++;

        offset += 2;
    }

    if (n % 2 == 1)
    {
        arr[mid][mid] = count++;
    }

    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            cout << arr[a][b] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> arr;
    int target = 6;
    generateMartrix(arr, target);

    system("pause");
    return 0;
}