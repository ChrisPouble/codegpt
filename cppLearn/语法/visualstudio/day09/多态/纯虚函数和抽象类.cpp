//#include <iostream>
//using namespace std;
//
////纯虚函数和抽象类
//class Base
//{
//public:
//
//    //纯虚函数
//    //只要有一个纯虚函数, 这个类称为抽象类
//    //抽象类特点:
//    //1,无法实际化对象
//    //2,抽象类的子类  必须要重写父亲中的纯虚函数, 否则也属于抽象类
//    virtual void func() = 0;
//};
//
//class son :public Base
//{
//public:
//    virtual void func()
//    {
//        cout << "我没有删了" << endl;
//    }
//};
//
//void test01()
//{
//    //Base b;  //抽象类是无法实际化对象
//    //new Base;//抽象类是无法实际化对象
//    
//    //son s; //子类必须要重写父亲中的纯虚函数, 否则也属于抽象类
//
//    Base* base = new son;
//    base->func();
//}
//
//int main()
//{
//    test01();
//    system("pause");
//    return 0;
//}