//#include <iostream>
//using namespace std;
//
////多态案例2 制作饮品
//class drinking
//{
//public:
//
//    //煮水
//    virtual void Boil() = 0;
//
//    //冲泡
//    virtual void Brew() = 0;
//
//    //倒入杯中
//    virtual void PourInCup() = 0;
//
//    //加入辅料
//    virtual void PutSomething() = 0;
//
//    //制作饮品
//    void makeDrink()
//    {
//        Boil();
//        Brew();
//        PourInCup();
//        PutSomething();
//    }
//};
//
////制作咖啡
//class Coffee :public drinking
//{
//public:
//    //煮水
//    virtual void Boil()
//    {
//        cout << "煮农夫山泉" << endl;
//    }
//
//    //冲泡
//    virtual void Brew()
//    {
//        cout << "冲泡咖啡" << endl;
//    }
//
//    //倒入杯中
//    virtual void PourInCup()
//    {
//        cout << "倒入杯中" << endl;
//    }
//
//    //加入辅料
//    virtual void PutSomething()
//    {
//        cout << "加入糖和牛奶" << endl;
//    }
//};
//
////制作茶叶
//class Tea :public drinking
//{
//public:
//    //煮水
//    virtual void Boil()
//    {
//        cout << "煮矿泉水" << endl;
//    }
//
//    //冲泡
//    virtual void Brew()
//    {
//        cout << "冲泡茶叶" << endl;
//    }
//
//    //倒入杯中
//    virtual void PourInCup()
//    {
//        cout << "倒入杯中" << endl;
//    }
//
//    //加入辅料
//    virtual void PutSomething()
//    {
//        cout << "加入柠檬和枸杞" << endl;
//    }
//};
//
//
////制作函数
//void dowork(drinking * abs)  //drinking * abs = new Coffee
//{
//    abs->makeDrink();
//    delete abs;
//}
//
//void test01()
//{
//    //制作咖啡
//    dowork(new Coffee);
//
//    cout << "---------------" << endl;
//    //制作茶叶
//    dowork(new Tea);
//}
//int main()
//{
//    test01();
//    system("pause");
//    return 0;
//}