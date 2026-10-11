//#include <iostream>
//#include <list>
//#include <algorithm>
//using namespace std;
//
////list数据存取
//void printList(const list<int>& l)
//{
//    for (list<int>::const_iterator it = l.begin(); it != l.end(); it++)
//    {
//        cout << *it << " ";
//    }
//    cout << endl;
//}
//
////反转
//void test01()
//{
//    list<int>l1;
//    l1.push_back(20);
//    l1.push_back(10);
//    l1.push_back(50);
//    l1.push_back(40);
//    l1.push_back(30);
//    
//    //反转
//    cout << "反转前: " << endl;
//    printList(l1);
//    
//    l1.reverse();
//    cout << "反转后: " << endl;
//    printList(l1);
//}
//
//bool cmp(int v1, int v2)
//{
//    //降序 第一个数大于第二个数
//    return v1 > v2;
//}
//
////排序
//void test02()
//{
//    list<int>l1;
//    l1.push_back(20);
//    l1.push_back(10);
//    l1.push_back(50);
//    l1.push_back(40);
//    l1.push_back(30);
//
//    //排序
//    cout << "排序前: " << endl;
//    printList(l1);
//
//    l1.sort(cmp); //sort(l1.begin(), l1.end()) 是不可以的
//    cout << "排序后: " << endl;
//    printList(l1);
//}
//
//int main()
//{
//    //test01();
//    test02();
//    system("pause");
//    return 0;
//}