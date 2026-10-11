//#include <iostream>
//using namespace std;
//
//
////继承中同名静态成员处理
//
//class Base
//{
//public:
//
//    static int m_A;
//
//    static void func()
//    {
//        cout << "Base - func()调用 " << endl;
//    }
//};
//int Base::m_A = 100;
//
//class son :public Base
//{
//public:
//    static int m_A;
//
//    static void func()
//    {
//        cout << "son - func()调用 " << endl;
//    }
//};
//int son::m_A = 200;
//
////同名静态成员属性
//void test01()
//{
//    //1, 通过对象访问
//    cout << "通过对象访问: " << endl;
//    son s;
//    cout << "son  下 m_A = " << s.m_A << endl;
//    cout << "Base 下 m_A = " << s.Base::m_A << endl;
//
//    //2, 通过类名访问
//    cout << "通过类名访问: "  << endl;
//    cout << "son  下 m_A = " << son::m_A << endl;
//    //第一个::代表通过类名方式访问   第二个::代表访问父类作用域下
//    cout << "Base 下 m_A = " << son::Base::m_A << endl;
//
//}
////同名静态成员函数
//void test02()
//{
//    //1, 通过对象访问
//    cout << "通过对象访问: " << endl;
//    son s;
//    s.func();
//    s.Base::func();
//
//    //2, 通过类名访问
//    cout << "通过类名访问: " << endl;
//    son::func();
//    son::Base::func();
//}
//
//int main()
//{
//    //test01();
//    test02();
//    system("pause");
//    return 0;
//}