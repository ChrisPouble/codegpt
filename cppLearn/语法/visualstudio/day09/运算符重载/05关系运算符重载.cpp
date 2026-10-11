//#include <iostream>
//using namespace std;
//
//class person 
//{
//public:
//    person(string name,int age)
//    {
//        m_name = name;
//        m_age = age;
//    }
//
//    //重载 == 号
//
//    bool operator==(person &p)
//    {
//        if(this->m_age == p.m_age && this->m_name == p.m_name)
//        {
//            return true;
//        }
//        return false;
//    }
//    bool operator!=(person& p)
//    {
//        if (this->m_age != p.m_age && this->m_name != p.m_name)
//        {
//            return true;
//        }
//        return false;
//    }
//
//    string m_name;
//    int m_age;
//};
//
//void test01()
//{
//    person p1("闵瑞", 10);
//
//    person p2("刘子晨", 10.5);
//
//    if(p1 == p2)
//    {
//        cout << "p1 和 p2是相等的! " << endl;
//    }
//    else
//    {
//        cout << "p1 和 p2是不相等的!" << endl;
//    }
//    if (p1 != p2)
//    {
//        cout << "p1 和 p2是不相等的! " << endl;
//    }
//    else
//    {
//        cout << "p1 和 p2是相等的!" << endl;
//    }
//
//int main()
//{
//    test01();
//    system("pause");
//    return 0;
//}