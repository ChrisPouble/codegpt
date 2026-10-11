//#include <iostream>
//#include <vector>
//using namespace std;
//
//int func(vector<int>& arr, int target)
//{
//    int slowindex = 0;
//    int fastindex = 0;
//
//    for (int i = 0; i < arr.size(); i++)
//    {
//        if (arr[fastindex] != target)
//        {
//            slowindex++;
//        }
//        fastindex++;
//    }
//    return slowindex;
//}
//
//void test01()
//{
//    vector<int> arr;
//    arr.push_back(4);
//    arr.push_back(5);
//    arr.push_back(4);
//    arr.push_back(4);
//    arr.push_back(6);
//    arr.push_back(4);
//    int target = 4;
//    int ret = func(arr, target);
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