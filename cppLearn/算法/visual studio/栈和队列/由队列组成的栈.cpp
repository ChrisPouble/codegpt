#include <iostream>
#include <queue>
using namespace std;

class myStack
{
public:
    queue<int> que;
    myStack()
    {

    }

    void push(int x)
    {
        que.push(x);
    }

    int pop()
    {
        int size = que.size();
        size--;
        while (size--)
        {
            int temp = que.front();
            que.pop();
            que.push(temp);
        }

        int result = que.front();
        que.pop();
        return result;
    }

    int top()
    {
        return que.back();
    }

    bool empty()
    {
        return que.empty() ? true : false;
    }
};

//int main()
//{
//    myStack que;
//    bool ret = que.empty();
//    
//    if (ret)
//    {
//        cout << "ret = true" << endl;
//    }
//    else
//    {
//        cout << "ret = false" << endl;
//    }
//
//    que.push(18);
//    que.push(22);
//    bool rey = que.empty();
//
//    if (rey)
//    {
//        cout << "rey = true" << endl;
//    }
//    else
//    {
//        cout << "rey = false" << endl;
//    }
//    cout << que.top() << endl;
//
//    cout << que.pop() << endl;
//    bool rez = que.empty();
//
//    if (rez)
//    {
//        cout << "rez = true" << endl;
//    }
//    else
//    {
//        cout << "rez = false" << endl;
//    }
//    system("pause");
//    return 0;
//}