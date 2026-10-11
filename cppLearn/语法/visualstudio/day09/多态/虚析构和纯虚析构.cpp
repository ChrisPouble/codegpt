//#include <iostream>
//#include <string>
//using namespace std;
//
////虚析构和纯虚析构
//
//class Animal
//{
//public:
//
//    Animal()
//    {
//        cout << "Animal构造函数调用" << endl;
//    }
//
//    //利用虚析够可以解决  父类指针释放子类对象时不干净的问题
//    //virtual ~Animal()
//    // {
//    //     cout << "Animal虚析构函数调用" << endl;
//    // }
// 
//    //纯虚析构   需要声明也需要实现
//    //有了纯虚析构  之后 , 这个类也属于抽象类, 无法实际化对象
//    virtual ~Animal() = 0;
//
//    //純虚函数
//    virtual void speak() = 0;
//
//};
//
//Animal::~Animal()
//{
//    cout << "Animal純虚析构函数调用" << endl;
//}
//
//
//
//class Cat :public Animal
//{
//public:
//
//    Cat(string name)
//    {
//        cout << "Cat构造函数调用" << endl;
//        m_name = new string(name);
//    }
//
//    virtual void speak()
//    {
//        cout << *m_name << "小猫在说话" << endl;
//    }
//
//    virtual ~Cat()
//    {
//        if (m_name != NULL)
//        {
//            cout << "Cat析构函数调用" << endl;
//            delete m_name;
//            m_name = NULL;
//        }
//    }
//
//    string* m_name;
//};
//
//void test01()
//{
//    Animal* animal = new Cat("Tom");
//    animal->speak();
//    //父类指针在析构时候   不会调用子类中析构函数, 导致子类如果有堆区属性, 出现内存泄漏
//    delete animal;
//}
//
//int main()
//{
//    test01();
//    system("pause");
//    return 0;
//}