#include <iostream>
#include <string>
using namespace std;

class Building;
class GoodGay
{
public:

    GoodGay();

    void visit();  //让visit函数可以访问Builling中私有成员
    void visit2();  //让visit2函数可以访问Builling中私有成员

    Building * building;

};

class Building
{
    friend void GoodGay::visit();

public:
    Building();

public:

    string m_sittingroom;//客厅

private:

    string m_bedroom;//卧室

};

//类外成员函数
Building::Building()
{
    m_sittingroom="ke ting";
    m_bedroom="wo shi";
}

GoodGay::GoodGay()
{
    building = new Building;
}

void GoodGay::visit()
{
    cout << "visit han shu diao yong: " <<building->m_sittingroom <<endl;
}
void GoodGay::visit2()
{
    cout << "visit han shu diao yong: " <<building->m_sittingroom <<endl;
}

void test01()
{
    GoodGay gg;
    gg.visit();
    gg.visit2();
}

int main()
{
    test01();
    return 0;
}
