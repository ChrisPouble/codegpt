#include <iostream>
using namespace std;

int test01(int arr[], int  size ,int s)
{
    int result = INT32_MAX;
    int sum = 0; //数值之和
    int i = 0; //起始位置
    int sub = 0; //滑动窗口的长度
    for(int j = 0; j < size; j++)
    {
        sum += arr[j];
        //精妙所在:
        //使用while循环,可以更新上一个数为起始点时计算的长度,
        //同时还可以检查去掉上一个起始点时,下一个起始点是否符合要求
        while(sum >= s)
        {
            sub = j - i + 1; //数组长度
            result = result < sub ? result : sub;
            sum -= arr[i++];
         
        }
    }
    return result == INT32_MAX ? 0 : result;
}

//int main()
//{
//    int size = 7;
//    int arr[] = { 4, 6, 2, 4, 9, 8, 7};
//    int s = 12;
//    int result = test01(arr, size, s);
//    cout << "result: " << result << endl;
//
//    system("pause");
//    return 0;
//}