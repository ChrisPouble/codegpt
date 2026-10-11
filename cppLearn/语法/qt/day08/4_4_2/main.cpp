#include <iostream>
#include <string>
using namespace std;

//类做友元

class Building;
class goodgay
{
public:

    goodgay();

    void visit();//参观函数 访问Building中的属性
    void visit2();

private:
    Building *building;

};

class Building
{
    //告诉编译器 goodGay类是Building类的好朋友，可以访问到Building类中私有内容
    friend void goodgay::visit();
public:
    Building();

public:

    string m_sittingroom;//客厅

private:

    string m_bedroom;//卧室
};

//类外写成员函数
Building::Building()
{
    m_sittingroom="ke ting";//客厅
    m_bedroom="wo shi";//卧室

}

goodgay::goodgay()
{
    //创建一个建筑物对象
    building = new Building;
}

void goodgay::visit()
{
    cout << "Hao ji you han shu fang wen: " <<building->m_sittingroom <<endl;
    cout << "Hao ji you han shu fang wen: " <<building->m_bedroom <<endl;
}

void goodgay::visit2()
{
    cout << "Hao ji you han shu fang wen: " <<building->m_sittingroom <<endl;
    //cout << "Hao ji you han shu fang wen: " <<building->m_bedroom <<endl; //报错!
}

void test01()
{
    goodgay gg;
    gg.visit();
    gg.visit2();
}

int main()
{
    test01();
    system("pause");
    return 0;
}
