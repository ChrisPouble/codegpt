#include <iostream>
#include <list>
#include <string>
using namespace std;

class Person
{
public:
    Person(string name, int age, int height)
    {
        this->m_Name = name;
        this->m_Age = age;
        this->m_Height = height;
    }

    string m_Name; //姓名
    int m_Age; //年龄
    int m_Height; //身高
};

//指定排序规则
bool cmp(Person p1, Person p2)
{
    if (p1.m_Age != p2.m_Age)
    {
        return p1.m_Age < p2.m_Age;
    }
    else
    {
        return p1.m_Height > p2.m_Height;
    }
}

void test01()
{
    //创建容器
    list<Person>l1;
    
    //准备数据
    Person p1("刘备", 35, 174);
    Person p2("曹操", 45, 181);
    Person p3("孙权", 41, 170);
    Person p4("赵云", 26, 190);
    Person p5("张飞", 35, 160);
    Person p6("关羽", 35, 200);
    Person p7("黄忠", 72, 155);
    Person p8("马超", 43, 189);
    Person p9("魏延", 36, 166);
    Person p10("貂蝉", 27, 135);
    Person p11("周瑜", 33, 172);
    Person p12("鲁肃", 35, 154);
    Person p13("诸葛亮", 45, 185);

    l1.push_back(p1);
    l1.push_back(p2);
    l1.push_back(p3);
    l1.push_back(p4);
    l1.push_back(p5);
    l1.push_back(p6);
    l1.push_back(p7);
    l1.push_back(p8);
    l1.push_back(p9);
    l1.push_back(p10);
    l1.push_back(p11);
    l1.push_back(p12);
    l1.push_back(p13);

    l1.sort(cmp);
    cout << "排序前: " << endl;
    for (list<Person>::iterator it = l1.begin(); it != l1.end(); it++)
    {
        cout << "姓名: " << (*it).m_Name << " "
            << "年龄: " << (*it).m_Age << " "
            << "身高: " << (*it).m_Height << "cm\n";
    }
    
    //排序
    cout << "---------------------------------" << endl;
    cout << "排序后: " << endl;

    l1.sort(cmp);
    for (list<Person>::iterator it = l1.begin(); it != l1.end(); it++)
    {
        cout << "姓名: " << (*it).m_Name << " "
            << "年龄: " << (*it).m_Age << " "
            << "身高: " << (*it).m_Height << "cm\n";
    }
}

int main()
{
    test01();
    system("pause");
    return 0;
}