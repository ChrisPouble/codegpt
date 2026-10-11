#include <iostream>

using namespace std;

//深拷贝与浅拷贝

class person
{
public:

    person()
    {
        cout<<"person de mo ren gou zao han shu diao yong"<<endl;//Person的默认构造函数调用
    }

    person(int age,int tall)
    {
        m_age=age;
        m_tall=new int(tall);
        cout<<"person de you can han gou zao shu de diao yong"<<endl;//Person的拷贝析构函数调用

    }

    //如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区问题
    person(const person &p)
    {
        cout<<"person de kao bei gou zao han shu diao yong"<<endl;//Person的有参构造函数调用
        m_age=p.m_age;
        m_tall=p.m_tall;
    }

    ~person()
    {
        //析构代码,将堆区开辟数据做释放操作
        if (m_tall != NULL)
        {
          delete m_tall;
        }

        cout<<"person xi gou han shu de diao yong"<<endl;//Person的析构函数调用
    }

    int m_age;//年龄
    int *m_tall;//身高
};

void test01(){
    person p1(18,160);
    cout << "p1 de age: " << p1.m_age <<"p1 de tall: "<<*p1.m_tall << endl;
    person p2(p1);
    cout << "p2 de age: " << p2.m_age <<"p2 de tall: "<<*p2.m_tall << endl;
}

int main()
{
    test01();
    system("pause");
    return 0;
}
