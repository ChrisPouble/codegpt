#include <iostream>
#include <deque>
#include <algorithm> //标准算法头文件
using namespace std;

//deque容器排序
void printDeque(const deque<int>& d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    deque<int>d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);

    //300 200 100 10 20 30
    printDeque(d);

    //排序  默认排序规则  从小到大 升序
    sort(d.begin(), d.end());
    cout << "排序后: " << endl;
    printDeque(d);
}

int main()
{
    test01();

    system("pause");
    return 0;
}