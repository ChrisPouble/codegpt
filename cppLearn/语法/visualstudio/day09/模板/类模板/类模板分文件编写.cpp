//#include <iostream>
//#include <string>
//#include "person.cpp"
//using namespace std;
//
////类模板分文件编写问题以及解决
//
////template<class T1,class T2>
////class Person
////{
////public:
////    Person(T1 name,T2 age);
////
////    void showPerson();
////
////    T1 m_Name;
////    T2 m_Age;
////};
//
////template<class T1,class T2>
////Person<T1,T2>::Person(T1 name, T2 age)
////{
////    this->m_Name = name;
////    this->m_Age = age;
////}
////
////template<class T1, class T2>
////void Person<T1,T2>::showPerson()
////{
////    cout << "姓名: " << this->m_Name << " 年龄: " << this->m_Age << endl;
////}
//
//void test01()
//{
//    Person <string, int>p("Jerry", 18);
//    p.showPerson();
//}
//
//int main()
//{
//
//    test01();
//    
//    system("pause");
//    return 0;
//}