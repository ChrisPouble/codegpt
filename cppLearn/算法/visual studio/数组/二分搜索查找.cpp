///*
//算法步骤:
//1.找出中间索引middle = (left + right)/2;
//2.比较目标值和中间值arr[middle] 和 target,搜索范围减半
//3.结束条件:
//    3.1:搜索范围小于0;
//    3.2:arr[middle]==target找到了
//注意事项:
//1.搜索范围是小于0,等于0也不能结束.
//*/
//
//
//#include <iostream>
//using namespace std;
//
//int binarySearch(int arr[], int  size, int target)
//{
//    int left = 0;
//    int right = size - 1;
//    int middle;
//    while (left <= right)
//    {
//        middle = (left + right) / 2;
//        if (arr[middle] < target)
//        {
//            left = middle + 1;
//        }
//        else if (arr[middle] > target)
//        {
//            right = middle - 1;
//        }
//        else
//        {
//            return middle;
//        }
//    }
//    return -1;
//}
//
//int main()
//{
//    int size = 10;
//    int arr[] = { 2, 4, 7, 9, 11, 22, 56, 124, 223, 229 };
//    int target = 10;
//    int result = binarySearch(arr, size, target);
//    cout << "result:" << result << endl;
//
//    system("pause");
//    return 1;
//}