#include <iostream>
#include <string>
using namespace std;

//类对象作为类成员


//手机类
class phone
{
public:

    phone(string pname)
    {
        cout<<"phone gou zao han shu de diao yong"<<endl;//Person的构造函数调用
        m_pname=pname;
    }

    ~phone()
    {
        cout<<"phone xi gou han shu de diao yong"<<endl;//Person的析构函数调用
    }

    //手机品牌名称
    string m_pname;

};

//人类
class person
{
public:

    //phone m_phone==phone pname 隐式转换法
    person(string name,string pname):m_name(name),m_phone(pname)
    {
         cout<<"person gou zao han shu de diao yong"<<endl;//Person的构造函数调用
    }

    ~person()
    {
        cout<<"person xi gou han shu de diao yong"<<endl;//Person的析构函数调用
    }

    //姓名
    string m_name;
    //手机
    phone m_phone;
};

//构造的顺序是 ：先调用对象成员的构造，再调用本类构造
//析构顺序与构造相反
void test01()
{
    person p("dabao","hua wei");
    cout << p.m_name <<" have a: "<<p.m_phone.m_pname<<" shou ji"<<endl;
}

int main()
{
    test01();
    return 0;
}
