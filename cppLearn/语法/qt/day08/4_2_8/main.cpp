#include <iostream>

using namespace std;

//静态成员变量
//所有对象共享同一个函数
//静态成员函数只能访问静态成员变量

class person
{
public:

    static void func()
    {
        m_a=100;//静态成员函数可以访问 静态成员变量
        //m_b=200; 报错//静态成员函数 不可以访问 非静态成员变量,无法区分到底是哪个对象的m_b
        cout<<"static void func de diao yong"<<endl;//static void func的调用
    }

    static int m_a;//静态成员变量
    int m_b;

    //静态成员函数也是有访问权限的
private:
    static void func2()
    {
        cout<<"static void func2 de diao yong"<<endl;//static void func2的调用
    }
};

int person::m_a=0;

void test01()
{
    //1,通过对象访问
    person p;
    p.func();

    //2,通过类名访问
    person::func();

    //person::func2(); 类外访问不到私有静态成员函数
}

int main()
{
    test01();
    return 0;
}
