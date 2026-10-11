#include <iostream>

using namespace std;

//构造函数调用规则
//1,创建一个类，c++编译器至少给一个类添加3个函数
// 默认构造函数 (空实现)
// 默认析构函数 (空实现)
// 默认拷贝构造函数 (值拷贝)


//2,
//如果我们提供有参构造，编译器不会提供默认构造，依然提供拷贝构造
//如果我们提供拷贝构造，编译器不会提供其他构造函数
class person
{
public:

    person()
    {
        cout<<"person de mo ren gou zao han shu diao yong"<<endl;//默认构造函数调用
    }

    person(int age)
    {

        cout<<"person de you can gou zao han shu diao yong"<<endl;//Person的拷贝析构函数调用
        m_age=age;
    }

    person(const person &p)
    {
        cout<<"person de kao bei gou zao han shu diao yong"<<endl;//Person的有参构造函数调用
        m_age=p.m_age;
    }

    ~person()
    {
        cout<<"person xi gou han shu de diao yong"<<endl;//Person的析构函数调用
    }

    int m_age;
};

void test01()
{
    person p;
    p.m_age=18;

    person p2(p);
    cout << "p2 de age: " << p2.m_age << endl;
}


void test02()
{
    person p(12);

    person p2(p);
    cout << "p2 de age: " << p2.m_age << endl;
}

void test03()
{
    person p(24);

    person p2(p);
    cout << "p2 de age: " << p2.m_age << endl;
}
int main()
{
    //test01();
    //test02();
    test03();
    cout << "Hello World!" << endl;
    return 0;
}
