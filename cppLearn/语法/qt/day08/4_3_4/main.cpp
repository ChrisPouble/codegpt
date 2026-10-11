#include <iostream>

using namespace std;

//常函数
class person
{
public:

    //this指针的本质 是指针常量   指针的指向是不可以修改的
    //const person * const this;
    void showperson() const
    {
        this->m_b=100;
        //this = NULL; //this指针不可以修改的指向的
    }

    void func()
    {

    }


    int m_a;
    mutable int m_b;//特殊变量,即使在常函数中,也可以修改这个值,加关键字mutable
};

void test01()
{
    person p;
    p.showperson();
}

//常对象

void test02()
{
    person p;//在对象前加const,变为常对象
    //p.m_a=100;
    p.m_b=100;

    //常对象只能调用常函数
    p.showperson();
    p.func();
}

int main()
{

    return 0;
}
