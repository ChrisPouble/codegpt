#include <iostream>

using namespace std;

//拷贝构造函数调用时机



class person
{
public:
    person()
    {
        cout<<"person de mo ren gou zao han shu diao yong"<<endl;//默认构造函数调用
    }

    person(int age){
        m_age=age;
        cout<<"person de you can gou zao han shu diao yong"<<endl;//Person的有参构造函数调用
    }

    person(const person &p){
        m_age=p.m_age;
        cout<<"person kao bei han gou zao shu de diao yong"<<endl;//Person的拷贝析构函数调用
    }

    ~person(){
        cout<<"person xi gou han shu de diao yong"<<endl;//Person的析构函数调用
    }


    int m_age;
};


//1,使用一个已经创建完毕的对象来初始化一个新对象
void test01()
{
    person p1(20);
    person p2(p1);
}

//2,值传递的方式给函数参数传

void dowork(person p)
{

}

void test02()
{
    person p;
    dowork(p);
}

//3,值方式返回局部对象

person dowork2()
{
    person p1;
    return p1;
}

void test03()
{
    person p=dowork2();

}

int main()
{
    //test01();
    //test02();
    test03();
    system("pause");
    return 0;
}
