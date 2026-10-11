//#include <iostream>
//using namespace std;
//
////继承方式
// 
//class Basel
//{
//public:
//    int m_A;
//protected:
//    int m_B;
//private:
//    int m_C;
//};
//
////公共继承
//class son1:public Basel
//{
//public:
//
//    void func()
//    {
//        m_A = 10; //父类中的公共权限成员 到子类中依然是公共权限
//        m_B = 10; //父类中的保护权限成员 到子类中依然是保护权限
//        //m_C = 10; //父类中的私有权限成员 子类访问不到
//    }
//};
//
//void test01()
//{
//    son1 s1;
//    s1.m_A = 100;
//    //s1.m_B = 100; //到son1中 m_B是保护权限 类外访问不到
//}
////保护继承
//class Base2
//{
//public:
//    int m_A;
//protected:
//    int m_B;
//private:
//    int m_C;
//};
//
//class son2:protected Base2
//{
//public:
//    void func()
//    {
//        m_A = 100; //父类中的公共权限成员 到子类中变为保护权限
//        m_B = 100; //父类中的保护权限成员 到子类中依然是保护权限
//        //m_C = 100; //父类中的私有权限成员 子类访问不到
//    }
//};
//
//void test02()
//{
//    son2 s1;
//    //s1.m_A = 1000;//在son2中 m_A变为保护权限 因此类外访问不到
//    //s1.m_B = 1000;//在son2中 m_B是保护权限 因此类外访问不到
//}
//
//
////私有继承
//class Base3
//{
//public:
//    int m_A;
//protected:
//    int m_B;
//private:
//    int m_C;
//};
//class son3:private Base3
//{
//public:
//    void func()
//    {
//        m_A = 100; //父类中的公共权限成员 到子类中变为私有权限
//        m_B = 100; //父类中的保护权限成员 到子类中变为私有权限
//        //m_C = 100; //父类中的私有权限成员 子类访问不到
//    }
//};
//class Grandson3:public son3
//{
//public:
//    void func()
//    {
//        //m_A = 1000; //在son3中 m_A变为私有权限, 即使是儿子, 也是访问不到
//        //98m_B = 1000; //在son3中 m_B变为私有权限, 即使是儿子, 也是访问不到
//    }
//
//};
//
//void test03()
//{
//    son3 s1;
//    //s1.m_A = 1000;//在son3中 m_A变为私有权限 因此类外访问不到
//    //s1.m_B = 1000;//在son3中 m_B变为私有权限 因此类外访问不到
//}
//
//
//int main()
//{
//    //test01();
//    system("pause");
//    return 0;
//}