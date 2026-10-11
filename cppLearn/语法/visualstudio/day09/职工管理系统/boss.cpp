#include "boss.h"
using namespace std;

//构造函数
Boss::Boss(int id, string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

//显示个人信息
void Boss::showInfo()
{
    cout << "职工编号: " << this->m_Id
        << "  职工姓名: " << this->m_Name
        << "  岗位: " << this->getDepName()
        << "  岗位职责: 管理公司所有事务" << endl;
}

//获取岗位名称
string Boss::getDepName()
{
    return string("老板");
}