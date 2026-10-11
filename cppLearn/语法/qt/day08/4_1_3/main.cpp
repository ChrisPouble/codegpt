#include <iostream>
#include <string>
using namespace std;

//成员属性设置为私有
//1,可以自己控制读写权限
//2,对于写可以检测数据的有效权限

//设计人类
class person{

public:

    //设置姓名
    void setname(string name){
        m_name=name;
    }
    //获取姓名
    string getname(){
        return m_name;
    }
    //获取年龄
    int getage(){
    m_age=12;
    return m_age;
    }
    //设置情人
    string setlover(string lover){
        m_lover=lover;
        return m_lover;
    }

private:

    //姓名 可读可写
    string m_name;
    //年龄 只读
    int m_age;
    //情人 只写
    string m_lover;
};

int main()
{
    person p;
    p.setname("laoliu");

    cout << "name: " <<p.getname()<< endl;
    cout << "age: " <<p.getage()<< endl;

    p.setlover("xiaoliu");
    return 0;
}
