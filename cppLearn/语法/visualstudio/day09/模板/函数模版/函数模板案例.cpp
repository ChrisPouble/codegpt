//#include <iostream>
//using namespace std;
//
////实现通用 对数组进行排序的函数
////规则 从大到小
////算法 冒泡
////测试 char数组, int数组
//
////排序算法
//template<class T>
//void mySort(T arr[], int len)
//{
//    for (int i = 0; i < len - 1; i++)
//    {
//        for (int j = 0; j < len - 1 - i; j++)
//        {
//            if (arr[j] > arr[j + 1])
//            {
//                T temp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = temp;
//            }
//        }
//    }
//}
//
////提供打印数组模板
//template<class T>
//void printArray(T arr[], int len)
//{
//    for (int i = 0; i < len; i++)
//    {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//}
//
//void test01()
//{
//    //测试char数组
//    char charArr[] = "badcfe";
//    int num = sizeof(charArr) / sizeof(char);
//    mySort(charArr, num);
//    printArray(charArr, num);
//
//}
//
//void test02()
//{
//    //测试int数组
//    int intArr[] = { 7,5,1,3,9,2,4,6,8 };
//
//    int num = sizeof(intArr) / sizeof(int);
//
//    mySort(intArr, num);
//    printArray(intArr, num);
//}
//
//int main()
//{
//    //test01();
//    test02();
//    system("pause");
//    return 0;
//}