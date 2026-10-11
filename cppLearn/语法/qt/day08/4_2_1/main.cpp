#include <iostream>

using namespace std;

//对象的初始化和清理
//1,构造函数 进行初始化操作
class person{
public:
    //1,构造函数
    //没有返回值 不用写void
    //函数名 与类名相同
    //构造函数可以有参数,可以发生重载
    //创建对象的时候候,构造函数会自动调用，而且只会调用一次
    person(){
        cout<<"person gou zao han shu de diao yong"<<endl;//Person的构造函数调用
    }

    //2,析构函数 进行清理的操作
    //1. 析没有返回值 不写void
    //2. 函数名称与类名相同,在名称前加上~
    //3. 析构函数不可以有参数，不可以发生重载
    //4. 对象在销毁前 会自动调用析构函数,而且只会调用一次
    ~person(){
        cout<<"person xi gou han shu de diao yong"<<endl;//Person的析构函数调用
    }
};


void test01(){
    person p;
}

int main()
{
    test01();
    system("pause");
    return 0;
}
