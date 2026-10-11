//#include <iostream>
//#include <string>
//using namespace std;
//
////类模板
//template<class NameType, class AgeType = int>
//class Person
//{
//public:
//    Person(NameType name, AgeType m_age)
//    {
//        this->m_Name = name;
//        this->m_Age = age;
//    }
//
//    void showPerson()
//    {
//        cout << "name: " << this->name << " age: " << this->age << endl;
//    }
//
//    NameType m_Name;
//    AgeType m_Age;
//};
//
////1,类模板没有自动类型推导使用方式
//void test01()
//{
//
//    //Person p("孙悟空", 1000); //错误, 无法用自动类型推导
//
//    Person<string>p("孙悟空", 1000); //正确, 只能用显示指定类型
//
//    p.showPerson();
//
//}
////2,类模板在模板参数列表中可以有默认参数
//void test02()
//{
//    Person<string, int>p1("猪八戒", 999);
//
//    p1.showPerson();
//}
//
//
//int main()
//{
//    //test01();
//    test02();
//    system("pause");
//    return 0;
//}