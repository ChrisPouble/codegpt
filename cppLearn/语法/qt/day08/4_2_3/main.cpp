#include <iostream>

using namespace std;

//1构造函数的分类及调用
//分类
//   按照参数分类   无参构造 (默认构造) 和 有参构造
//   按照类型分类   普通构造 拷贝构造
class person{
public:
    //构造函数
    person(){
        cout<<"person de wu can gou zao han shu diao yong"<<endl;//Person的无参构造函数调用
    }

    person(int a){
        age=a;
        cout<<"person de you can gou zao han shu diao yong"<<endl;//Person的有参构造函数调用
    }

    //拷贝构造函数
    person(const person &p){
        //将传入的人身上的所有属性,拷贝到我身上
        age=p.age;
        cout<<"person kao bei han gou zao shu de diao yong"<<endl;//Person的拷贝析构函数调用
    }

    ~person(){
        cout<<"person xi gou han shu de diao yong"<<endl;//Person的析构函数调用
    }

    int age;
};

//调用
void test01(){

    //1,括号法
    person p1;//默认构造函数调用
    person p2(10);//有参构造函数调用
    person p3(p2);//拷贝构造函数调用

    //2,显示法
    person p4=person(10);//有参构造函数调用
    person p5=person(p4);//拷贝构造函数调用
    person(10);//单独写就是匿名对象 当前行结束之后，马上析构

    //3,隐式转换法
    person p6=10;//有参构造函数调用
    person p7=p6;//拷贝构造函数调用
}

int main()
{
    test01();
    cout << "Hello World!" << endl;
    return 0;
}
