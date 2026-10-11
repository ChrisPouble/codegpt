//#include <iostream>
//using namespace std;
//
////继承中的构造和析构的顺序
//class Base
//{
//public:
//    Base()
//    {
//        cout << "Base构造函数!" << endl;
//    }
//
//    ~Base()
//    {
//        cout << "Base析构函数!" << endl;
//    }
//};
//
//class son :public Base
//{
//public:
//    son()
//    {
//        cout << "son构造函数!" << endl;
//    }
//
//    ~son()
//    {
//        cout << "son析构函数!" << endl;
//    }
//
//};
//
//void test01()
//{
//    //Base b;
//
//    //继承中的构造和析构的顺序如下:
//    //先构造父类, 在构造子类 , 析构的顺序与构造的顺序相反
//    son s;
//}
//
//int main()
//{
//    test01();
//    system("pause");
//    return 0;
//}