#include <iostream>
#include <string>
using namespace std;

//建筑物类
class building
{
    //goodgay全局函数是 building,可以访问building中私有成员
    friend void goodgay(building &build);

public:
    building()
    {
        m_sittingroom="ke ting";//客厅
        m_bedroom="wo shi";//卧室
    }
public:


    string m_sittingroom;//客厅

private:
    string m_bedroom;//卧室

};

//全局函数
void goodgay(building &build) //好基友
{
    cout << "hao ji you han shu fang wen  : " <<build.m_sittingroom <<endl;

    cout << "hao ji you han shu fang wen: " <<build.m_bedroom <<endl;
}

void test01()
{
    building build;
    goodgay(build);
}

int main()
{
    test01();
    return 0;
}
