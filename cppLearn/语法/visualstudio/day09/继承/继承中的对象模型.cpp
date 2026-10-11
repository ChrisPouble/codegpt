//#include <iostream>
//using namespace std;
//
////继承中的对象模型
//
//class Base
//{
//public:
//    int m_a; 
//protected:
//    int m_B;
//private:
//    int m_C;
//};
//
//class son:public Base
//{
//public:
//
//    int m_d;
//};
//
//
//void test01()
//{
//    // 父类中所有非静态成员都会被子类继承下去
//    // 父类中私有成员属性 是被编译器给隐藏了, 因此是访问不到的, 但是确实被继承下去了
//    cout << "size of son = " << sizeof(son) << endl;//16
//
//}
//
//int main()
//{
//    test01();
//    system("pause");
//    return 0;
//}