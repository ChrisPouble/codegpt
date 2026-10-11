#include <iostream>

using namespace std;

//圆周率
const double pi=3.14;

//设计一个圆类,求圆的周长
//圆求周长的公式: 2 * pi * 半径

//class 代表设计一个类,类后面紧跟着的就是类名称
class yuan{
    //访问权限
    //公共权限
public:

    //属性
    //半径
    double m_r;

    //行为
    //获取圆的周长
    double calculate(){
        return 2*pi*m_r;
    }
};

int main()
{
    //通过圆类,创建圆的对象
    //c1就是一个具体的圆
    yuan c1;
    c1.m_r=10;
    cout << "yuan de zhou chang wei: " <<c1.calculate()<< endl;
    return 0;
}
