//#include <iostream>
//#include <functional> //内建函数对象头文件
//using namespace std;
//
////内建函数对象  算数仿函数
//
////negate 一元仿函数  取反仿函数
//void test01()
//{
//    negate<int>n;
//    cout << n(50) << endl;
//}
//
///*
//  plus       二元仿函数  加法仿函数
//  minus      二元仿函数  减法仿函数
//  multiplies 二元仿函数  乘法仿函数
//  divides    二元仿函数  除法仿函数
//  modulus    二元仿函数  取模仿函数
//*/
//void test02()
//{
//    plus<int>p;
//    cout << p(10, 20) << endl;
//
//    minus<int>mi;
//    cout << mi(40, 20) << endl;
//
//    multiplies<int>mu;
//    cout << mu(15, 20) << endl;
//
//    divides<float>d;
//    cout << d(10, 20) << endl;
//
//    modulus<int>mo;
//    cout << mo(35, 20) << endl;
//}
//
//int main()
//{
//    test01();
//    test02();
//    system("pause");
//    return 0;
//}