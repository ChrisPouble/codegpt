//#include <iostream>
//
//using namespace std;
//
////加号运算符重载
//
//class person
//{
//public:
//
//    //1,成员函数重载+号
////    person operator+(person &p)
////    {
////        person temp;
////        temp.m_a=this->m_a+p.m_a;
////        temp.m_b=this->m_b+p.m_b;
////        return temp;
////    }
//
//    int m_a;
//    int m_b;
//};
//
////2,全局函数重载+号
//person operator+(person& p1, person p2)
//{
//    person temp;
//    temp.m_a = p1.m_a + p2.m_a;
//    temp.m_b = p1.m_b + p2.m_b;
//    return temp;
//}
//
//person operator+(person p3, int val)
//{
//    person temp;
//    temp.m_a = p3.m_a + val;
//    temp.m_b = p3.m_b + val;
//    return temp;
//}
//
//void test01()
//{
//
//    person p1;
//    p1.m_a = 10;
//    p1.m_b = 10;
//
//    person p2;
//    p2.m_a = 10;
//    p2.m_b = 10;
//
//    //成员函数重载本质调用
//    //person p3=p1.operator+(p2);
//
//    //全局函数重载本质调用
//    //person p3=operator+(p1,p2);
//
//    person p3 = p1 + p2;
//    //运算符重载 也可以发生函数重载
//
//    cout << "p.m_a= " << p3.m_a << endl;
//    cout << "p.m_b= " << p3.m_b << endl;
//
//    person p4 = p3 + 10; //相当于 operator+(p3,10)
//    cout << "m_a: " << p4.m_a << endl;
//    cout << "m_b: " << p4.m_a << endl;
//}
//
////int main()
////{
////    test01();
////    return 0;
////}
