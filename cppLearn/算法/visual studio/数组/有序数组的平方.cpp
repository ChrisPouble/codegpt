#include <iostream>
using namespace std;

void test01(int arr[], int size, int* result)
{
    int k = size - 1;

    //i <= j 一定要有等于号,否则会少排序一个
    for (int i = 0, j = size - 1; i <= j;)
    {
        if (arr[i] * arr[i] >= arr[j] * arr[j])
        {
            result[k] = arr[i] * arr[i];
            k--;
            i++;
        }else
        {
            result[k] = arr[j] * arr[j];
            k--;
            j--;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << result[i] << ", ";
    }
    cout << endl;
}

//int main()
//{
//    const int size = 4;
//    int arr[] = { -5, 1, 2, 3 };
//    int result[size];
//    test01(arr, size, result);
//
//    system("pause");
//    return 0;
//}
