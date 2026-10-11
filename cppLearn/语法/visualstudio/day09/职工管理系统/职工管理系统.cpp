#include <iostream>
#include "workerManageer.h"
using namespace std;

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main()
{
    //测试代码:
    /*Worker* worker = NULL;
    worker = new Employee(1, "小宝", 1);
    worker->showInfo();
    delete worker;

    worker = new Manager(2,"闵瑞",2);
    worker->showInfo();
    delete worker;


    worker = new Boss(3, "彭哲君",3);
    worker->showInfo();
    delete worker;*/

    //实际化管理者对象
    WorkerManager wm;

    int choice = 0; //用来存储用户的选项

    while (1)
    {
        //调用展示菜单成员函数
        wm.Show_Menu();

        cout << "请输入您的选择: " << endl;
        cin >> choice; // 接受用户的选项

        switch (choice)
        {
        case 0:  //退出系统
            wm.ExitSystem();
            break;
        case 1:  //增加职工
            wm.Add_Emp();
            break;
        case 2:  //显示职工
            wm.Show_Emp();
            break;
        case 3:  //删除职工
            wm.Del_Emp();
            break; 
        case 4:  //修改职工
            wm.Mod_Emp();
            break;
        case 5:  //查找职工
            wm.Find_Emp();
            break;
        case 6:  //排序职工
            wm.Sort_Emp();
            break;
        case 7:  //清空文档
            wm.Clean_File();
            break;
        default:
            system("cls"); //清屏
            break;
        }

    }

    //调用展示菜单成员函数
    wm.Show_Menu();

    system("pause");

    return 0;
}