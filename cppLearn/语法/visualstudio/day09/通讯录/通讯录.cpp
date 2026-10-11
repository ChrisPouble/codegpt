#include <iostream>
#include <string>
using namespace std;

//联系人结构体
struct person
{
    string m_name;//姓名
    int m_sex;//性别 :1男, 2女
    int m_age;//年龄
    string m_phone;//电话
    string m_addr;//住址
};

const int constmax = 1000;
struct Addressbooks
{
    struct person personarray[constmax];
    int m_size;
};

//1,添加联系人
void addperson(Addressbooks* abs)
{
    if (abs->m_size == constmax)
    {
        cout << "已经满人了: " << endl;
        return;
    }
    else
    {
        //姓名
        string name;
        cout << "请输入姓名: " << endl;
        cin >> name;
        abs->personarray[abs->m_size].m_name = name;

        //性别
        cout << "请输入性别: " << endl;
        cout << "1---男 " << endl;
        cout << "2---女 " << endl;
        int sex = 0;

        while (1)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personarray[abs->m_size].m_sex = sex;
                break;
            }
            cout << "输入有误, 请重新输入: " << endl;
        }

        //年龄
        cout << "请输入年龄: " << endl;
        int age = 0;
        cin >> age;
        abs->personarray[abs->m_size].m_age = age;

        //电话
        cout << "请输入电话: " << endl;
        string phone = "0";
        cin >> phone;
        abs->personarray[abs->m_size].m_phone = phone;

        //住址
        cout << "请输入住址: " << endl;
        string addr = "0";
        cin >> addr;
        abs->personarray[abs->m_size].m_addr = addr;

        abs->m_size++;

        cout << "添加成功!" << endl;
        system("pause"); //请按任意键继续
        system("cls"); //清屏
    }
}

//2,显示联系人
void showperson(Addressbooks* abs)
{
    if (abs->m_size == 0)
    {
        cout << "当前记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_size; i++)
        {
            cout << "姓名: " << abs->personarray[i].m_name << "  ";
            cout << "性别: " << (abs->personarray[i].m_sex == 1 ? "男" : "女") << "  ";
            cout << "年龄: " << abs->personarray[i].m_age << "  ";
            cout << "电话: " << abs->personarray[i].m_phone << "  ";
            cout << "住址: " << abs->personarray[i].m_addr << "  " << endl;
        }
    }

    system("pause"); //请按任意键继续
    system("cls"); //清屏
}

int isExist(Addressbooks* abs, string name)
{
    for (int i = 0; i < abs->m_size; i++)
    {
        if (abs->personarray[i].m_name == name)
        {
            return i;
        }
    }
    return -1;
}

//3,删除联系人
void deleteperson(Addressbooks* abs)
{
    cout << "请输入删除联系人姓名: " << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1)
    {
        for (int i = ret; i < abs->m_size; i++)
        {
            abs->personarray[i] = abs->personarray[i + 1];
        }
        abs->m_size--;
        cout << "删除成功!" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("pause"); //请按任意键继续
    system("cls"); //清屏
}

//4,查找联系人
void findperson(Addressbooks* abs)
{
    cout << "请输入要查找联系人姓名: " << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);


    if (ret != -1)
    {   
        cout << "姓名: " << abs->personarray[ret].m_name << "  ";
        cout << "性别: " << (abs->personarray[ret].m_sex == 1 ? "男" : "女") << "  ";
        cout << "年龄: " << abs->personarray[ret].m_age << "  ";
        cout << "电话: " << abs->personarray[ret].m_phone << "  ";
        cout << "住址: " << abs->personarray[ret].m_addr << "  " << endl;

    }
    else
    {   
        cout << "查无此人" << endl;
    }
    system("pause"); //请按任意键继续
    system("cls"); //清屏
}

//5,修改联系人
void modifyperson(Addressbooks* abs)
{
    cout << "请输入修改联系人姓名: " << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1)
    {
        //姓名
        string name;
        cout << "请输入姓名" << endl;
        cin >> name;
        abs->personarray[ret].m_name = name;
        
        //性别
        cout << "请输入性别" << endl;
        cout << "1---男" << endl;
        cout << "2---女" << endl;
        int sex = 0;
        cin >> sex;

        while (1)
        {
            if (sex == 1 || sex == 2)
            {
                abs->personarray[ret].m_sex = sex;
                break;
            }
            cout << "请重新输入" << endl;
        }

        //年龄
        cout << "请输入年龄" << endl;
        int age = 0;
        cin >> age;
        abs->personarray[ret].m_age = age;

        //电话
        cout << "请输入电话" << endl;
        string phone = "";
        cin >> phone;
        abs->personarray[ret].m_phone = phone;

        //住址
        cout << "请输入住址" << endl;
        string addr = "";
        cin >> addr;
        abs->personarray[ret].m_addr = addr;

        cout << "修改成功!" << endl;
    }
    else //没找到
    {
        cout << "查无此人" << endl;
    }
    system("pause"); //请按任意键继续
    system("cls"); //清屏
}

//6,清空联系人
void cleanperson(Addressbooks* abs)
{
    abs->m_size = 0;
    cout << "通讯录以清空" << endl;
    system("pause"); //请按任意键继续
    system("cls"); //清屏
}

//菜单显示
void showmenu() {
    cout << "********************************************" << endl;
    cout << "*************** 1,添加联系人 ***************" << endl;
    cout << "*************** 2,显示联系人 ***************" << endl;
    cout << "*************** 3,删除联系人 ***************" << endl;
    cout << "*************** 4,查找联系人 ***************" << endl;
    cout << "*************** 5,修改联系人 ***************" << endl;
    cout << "*************** 6,清空联系人 ***************" << endl;
    cout << "*************** 0,退出通讯录 ***************" << endl;
    cout << "********************************************" << endl;
}


int main()
{
    Addressbooks abs;
    abs.m_size = 0;

    int select = 0;

    while (1)
    {
        showmenu();//显示菜单
        cin >> select;
        switch (select)
        {
        case 1: //1,添加联系人
            addperson(&abs);
            break;
        case 2: //2,显示联系人
            showperson(&abs);
            break;
        case 3: //3,删除联系人
            deleteperson(&abs);
            break;
        case 4: //4,查找联系人
            findperson(&abs);
            break;
        case 5: //5,修改联系人
            modifyperson(&abs);
            break;
        case 6: //6,清空联系人
            cleanperson(&abs);
            break;
        case 0: //0,退出通讯录
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
            
        default:
            break;
        }
    }
    system("pause");
    return 0;
}