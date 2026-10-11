//#include <iostream>
//using namespace std;
//
//
////递增运算符重载
//
////自定义整型
//class myinteger
//{
//    friend ostream& operator<<(ostream& out, myinteger myint);
//
//public:
//    myinteger()
//    {
//        m_num = 0;
//    }
//
//    //重载前置++运算符  返回引用为了一直对一个数据进行递增操作
//    myinteger& operator++()
//    {
//        //先进行++运算
//        m_num++;
//
//        //再将自身做返回
//        return *this;
//    }
//
//    //重载后置++运算符
//    //void operator++(int)  int代表占位参数, 可以用于区分前置和后置递增
//    myinteger operator++(int)
//    {
//        //先 记录当时结果
//        myinteger temp = *this;//(*this).m_num=11 (temp).m_num=11 
//        //后 递增
//        m_num++;
//        //最后将记录结果做返回
//        return temp;
//    }
//
//private:
//    int m_num;
//
//};
//
//
////重载<<运算符
//ostream& operator<<(ostream& out, myinteger myint)
//{
//    out << myint.m_num;
//    return out;
//}
//
//void test01()
//{
//    myinteger myint;
//
//    cout << ++myint << endl;
//    cout << myint << endl;
//}
//
//void test02()
//{
//    myinteger myint;// myint.m_num = 0 
//    //myinteger x = myint++;
//   cout << myint++;//temp.m_num=0 myint.m_num = 1
//    cout << myint << endl;
//}
//
//int main()
//{
//    //test01();
//    test02();
//    system("pause");
//    return 0;
//}
