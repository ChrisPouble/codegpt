//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <functional> //内建函数对象头文件
//using namespace std;
//
////内建函数对象  关系仿函数
///*
//  等于     equal_to
//  不等于   not_equal_to
//  大于     greater
//  大于等于 greater_equal
//  小于     less
//  小于等于 less_equal
//*/
//class MyCompare
//{
//public:
//    bool operator()(int val1, int val2)
//    {
//        return val1 > val2;
//    }
//};
//
//void test01()
//{
//    vector<int>v;
//
//    v.push_back(10);
//    v.push_back(30);
//    v.push_back(40);
//    v.push_back(20);
//    v.push_back(50);
//
//    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//    {
//        cout << *it << " ";
//    }
//    cout << endl;
//
//    //降序
//    //sort(v.begin(), v.end(), MyCompare());
//    //greater<int>()  内建函数对象
//    sort(v.begin(), v.end(), greater<int>());
//    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
//    {
//        cout << *it << " ";
//    }
//    cout << endl;
//}
//
//int main()
//{
//    test01();
//    system("pause");
//    return 0;
//}