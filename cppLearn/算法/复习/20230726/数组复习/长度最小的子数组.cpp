//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int func(vector<int> arr, int target)
//{
//    int result = INT32_MAX; //最终的结果
//    int sum = 0; //元素之和
//    int sub = 0; //子数组长度
//
//    for(int i = 0; i < arr.size(); i++)
//    {
//        sum = 0;
//        for (int j = i; j < arr.size(); j++)
//        {
//            sum += arr[j];
//            if(sum >= target)
//            {
//                sub = j - i + 1;
//                result = result < sub ? result : sub;
//                break;
//            }
//        }
//    }
//    int temp = result == INT32_MAX ? 0 : result;
//    return temp;
//}
//
//int func1(vector<int>& arr, int target)
//{
//    int result = INT32_MAX; //最终的结果
//    int sum = 0; //元素之和
//    int sub = 0; //子数组长度
//    int i = 0;
//
//    for (int j = 0; j < arr.size(); j++)
//    {
//        sum += arr[j];
//        while(sum >= target)
//        {
//            sub = j - i + 1;
//            result = result < sub ? result : sub;
//            sum -= arr[i];
//            i++;
//        }
//    }
//    int temp = result == INT32_MAX ? 0 : result;
//    return temp;
//}
//
//void test01()
//{
//    vector<int> arr;
//    arr.push_back(4);
//    arr.push_back(6);
//    arr.push_back(2);
//    arr.push_back(4);
//    arr.push_back(9);
//    arr.push_back(8);
//    arr.push_back(7);
//    int target = 12;
//    int ret = func1(arr, target);
//
//    cout << "ret = " << ret << endl;
//}
//
////int main()
////{
////    test01();
////    system("pause");
////    return 0;
////}