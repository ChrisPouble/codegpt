#include "employee.h"

//构造函数
Employee::Employee(int id, string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

//显示个人信息
void Employee::showInfo()
{
    cout << "职工编号: " << this->m_Id 
         << "  职工姓名: " << this->m_Name 
         << "  岗位: " << this->getDepName() 
         << "  岗位职责: 完成经理交给的任务" << endl;
}
//获取岗位名称
string Employee::getDepName()
{
    return string("普通员工");
}