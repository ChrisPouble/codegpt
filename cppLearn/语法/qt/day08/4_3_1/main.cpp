#include <iostream>

using namespace std;

// 成员变量 和 成员函数 分开存储的

class person
{

    int m_a;//非静态成员变量  属于类的对象上

    static int m_b;//静态成员变量  不属于类的对象上

    void func() {}//非静态成员函数  不属于类的对象上

    static void func2() {}//静态成员函数  不属于类的对象上
};

int person::m_b=0;

void test01()
{
    person p;
    //空对象占用的内存空间为: 1
    cout<<"sizeof p = "<<sizeof(p)<<endl;
}

void test02()
{
    person p;
    cout<<"sizeof p = "<<sizeof(p)<<endl;
}

int main()
{
    //test01();
    test02();
    return 0;
}
