#include <iostream>
#include <string>
using namespace std;

//联系人结构体
struct person
{
    string m_name;//姓名
    int m_sex;//性别: 1男 2女
    int m_age;//年龄
    string m_phone;//电话
    string m_addr;//住址
};

#define max 1000
//通讯录结构体
struct Addressbooks
{
    struct person personarray[max];//通讯录中保存的联系人数组 1000为最大人数
    int m_size;//通讯录中当前记录联系人个数
};

//1,添加联系人
void addperson(Addressbooks *abs)
    {
    //判断通讯录是否已满,如果满了就不再添加
    if(abs->m_size==max)
    {
        cout<<"yi jing man ren le: "<<endl;
        return;
    }
    else
    {
        //添加具体的联系人

        //姓名
        string name;
        cout<<"qing shu ru xing ming"<<endl;//请输入姓名
        cin>>name;
        abs->personarray[abs->m_size].m_name=name;

        //性别: 1男 2女
        cout<<"qing shu ru xing bie: "<<endl;//请输入性别
        cout<<"1---man "<<endl;//1---男
        cout<<"2---woman "<<endl;//2---女
        int sex=0;

        while(1)
        {
            cin>>sex;
            if(sex==1||sex==2)
            {
                abs->personarray[abs->m_size].m_sex=sex;
                break;
            }
            cout<<"shu ru you wu,qing chong xin shu ru"<<endl;//输入有误,请重新输入
        }

        //年龄
        cout<<"qing shu ru nian ling: "<<endl;//请输入年龄
        int age=0;
        cin>>age;
        abs->personarray[abs->m_size].m_age=age;

        //电话
        cout<<"qing shu ru dian hua: "<<endl;//请输入电话
        string phone="0";
        cin>>phone;
        abs->personarray[abs->m_size].m_phone=phone;

        //住址
        cout<<"qing shu ru zhu zhi: "<<endl;//请输入住址
        string addr="0";
        cin>>addr;
        abs->personarray[abs->m_size].m_addr=addr;

        //更新通讯录人数
        abs->m_size++;

        cout<<"tian jia cheng gong"<<endl;//添加成功
        system("pause");//请按任意键继续
        system("cls");//清屏操作


    }
}

//2,显示联系人
void showperson(Addressbooks *abs)
{
    //判断通讯录中人数是否为0,如果为0,提示记录为空
    //如果不为0,显示记录的联系人信息
    if(abs->m_size==0)
    {
        cout<<"dang qian ji lu wei kong"<<endl;//判断通讯录中人数是否为0//当前记录为空
    }
    else
    {
        for (int i = 0; i < abs->m_size; i++)
        {
            cout<<"name: "<<abs->personarray[i].m_name<<"  ";//姓名
            cout<<"sex: "<<(abs->personarray[i].m_sex ==1 ?"man":"woman")<<"  ";//性别
            cout<<"age: "<< abs->personarray[i].m_age<<"  ";//年龄
            cout<<"phone: "<<abs->personarray[i].m_phone<<"  ";//电话
            cout<<"addr: "<< abs->personarray[i].m_addr<<"  "<<endl;//住址
        }
    }
    system("pause");//请按任意键继续
    system("cls");//清屏操作

}

//检测联系人是否存在,如果存在,返回联系人所在数组中具体位置,不存在返回-1
//参数1 通讯录 参数2 对比姓名
int isExist(Addressbooks *abs,string name)
{
    for (int i=0;i<abs->m_size;i++)
    {
        //找到用户姓名了
        if(abs->personarray[i].m_name == name)
        {
            return i;//找到了,返回这个人在数组中的下标编号
        }
    }
    return -1;//如果遍历结束都没找到,返回-1
}

//3,删除联系人
void deleteperson(Addressbooks *abs)
{
    cout<<"qing shu ru shan chu lian xi ren xing ming: "<<endl;//请输入删除联系人姓名
    string name;
    cin>>name;

    //ret==-1  未查到
    //ret!=-1  查到了
    int ret=isExist(abs,name);
    if(ret != -1)
    {
        //找到此人
        for (int i=ret;i<abs->m_size; i++)
        {
            //数据迁移
            abs->personarray[i]=abs->personarray[i+1];
        }
        abs->m_size--;//更新通讯录中的人员数
        cout<<"shan chu cheng gong"<<endl;//删除成功
    }
    else
    {
        cout<<"cha wu ci ren"<<endl;//查无此人

    }
    system("pause");//请按任意键继续
    system("cls");//清屏操作
}

//4,查找联系人
void findperson(Addressbooks *abs)
{
    cout<<"qing shu ru ni yao cha zhao de lian xi ren: "<<endl;//请输入你要查找的联系人
    string name;
    cin>>name;

    //判断指定的联系人是否存在通讯录中
    int ret=isExist(abs,name);


    if(ret != -1)
    {  //找到联系人
        cout<<"name: "<<abs->personarray[ret].m_name<<"  ";//姓名
        cout<<"sex: "<<(abs->personarray[ret].m_sex ==1 ?"man":"woman")<<"  ";//性别
        cout<<"age: "<< abs->personarray[ret].m_age<<"  ";//年龄
        cout<<"phone: "<<abs->personarray[ret].m_phone<<"  ";//电话
        cout<<"addr: "<< abs->personarray[ret].m_addr<<"  "<<endl;//住址

    }
    else
    {  //未找到联系人
        cout<<"cha wu ci ren"<<endl;//查无此人
    }
    system("pause");//请按任意键继续
    system("cls");//清屏操作
}

//5,修改联系人
void modifyperson(Addressbooks *abs)
{
    cout<<"qing shu ru xiu gai lian xi ren xing ming: "<<endl;//请输入修改联系人姓名
    string name;
    cin>>name;

    int ret=isExist(abs,name);
    if(ret !=-1) //找到联系人
    {
        //姓名
        string name;
        cout<<"qing shu ru xing ming"<<endl;
        cin>>name;
        abs->personarray[ret].m_name=name;
        //性别
        cout<<"qing shu ru xing bie"<<endl;
        cout<<"1---man"<<endl;
        cout<<"2---woman"<<endl;
        int sex=0;
        cin>>sex;

        while(1)
        {
            if(sex==1||sex==2)
            {
                //输入正确,退出循环输入
                abs->personarray[ret].m_sex=sex;
                break;
            }
            cout<<"qing chong xin shu ru"<<endl;//请重新输入
        }

        //年龄
        cout<<"qing shu ru nian lian"<<endl;//请输入年龄
        int age=0;
        cin>>age;
        abs->personarray[ret].m_age=age;

        //电话
        cout<<"qing shu ru dian hua"<<endl;//请输入电话
        string phone="";
        cin>>phone;
        abs->personarray[ret].m_phone=phone;

        //住址
        cout<<"qing shu ru zhu zhi"<<endl;//请输入住址
        string addr="";
        cin>>addr;
        abs->personarray[ret].m_addr=addr;

        cout<<"xiu gai cheng gong!"<<endl;//修改成功
    }
    else //未找到联系人
    {
        cout<<"cha wu ci ren"<<endl;//查无此人
    }
    system("pause");//请按任意键继续
    system("cls");//清屏操作
}

//6,清空联系人
void cleanperson(Addressbooks *abs)
{
    abs->m_size=0;//将当前通讯录人数置为0
    cout<<"tong xun lu yi qing kong"<<endl;//通讯录已清空
    system("pause");//请按任意键继续
    system("cls");//清屏操作
}

//菜单界面
void showmenu(){
    cout<<"***********************************"<<endl;
    cout<<"***** 1,tian jia lian  xi ren *****"<<endl;//1,添加联系人
    cout<<"***** 2,xian shi lian  xi ren *****"<<endl;//2,显示联系人
    cout<<"***** 3,shan chu lian  xi ren *****"<<endl;//3,删除联系人
    cout<<"***** 4,cha zhao lian  xi ren *****"<<endl;//4,查找联系人
    cout<<"***** 5,xiu gai  lian  xi ren *****"<<endl;//5,修改联系人
    cout<<"***** 6,qing kong lian xi ren *****"<<endl;//6,清空联系人
    cout<<"***** 0,tui chu tong xun  lu  *****"<<endl;//0,退出通讯录
    cout<<"***********************************"<<endl;
}


int main()
{
    //创建通讯录结构体变量
    Addressbooks abs;
    //初始化当前通讯录中人数
    abs.m_size=0;

    int select=0;

    while(1)
    {
        showmenu();//菜单调用
        cin>>select;
        switch(select)
        {

        case 1: //1,添加联系人
            addperson(&abs);//参数为地址,可修饰实参
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
            cout<<"huan ying xia ci shi yong"<<endl;//欢迎下次使用
            system("pause");
            return 0;
        default:
            break;
        }
    }
    system("pause");
    return 0;
}
