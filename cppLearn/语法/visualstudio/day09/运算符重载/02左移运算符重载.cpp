//#include <iostream>
//using namespace std; 
//
////左移运算符重载
//
//class person
//{
//    friend ostream& operator<<(ostream& cout, person& p);
//
//public:
//    person(int a,int b)
//    {
//        m_a = a;
//        m_b = b;
//    }
//private:
//
//    //利用成员函数重载 左移运算符   p.operator<<(cout) 简化版本 p << cout
//    //我们通常不会利用成员函数重载<<运算符,因为无法实现 cout在左侧 
//    //void operator<<(cout)
//    //{
//    //
//    //}
//
//    int m_a;
//    int m_b;
//};
//
////只能利用全局函数重载左移运算符
//ostream & operator<<(ostream &cout, person &p) //本质 operator<<(cout,p) 简化 cout << p
//{
//    cout << "m_a = " << p.m_a <<" m_b =" << p.m_b;
//    return cout;
//}
//
//void test01()
//{
//    person p(10,10);
//    //p.m_a = 10;
//    //p.m_b = 10;    
//
//    cout << p <<" hello world"<<endl;//链式编程
//}
//
//int main()
//{
//    test01();
//
//    system("pause");
//    return 0;
//}
