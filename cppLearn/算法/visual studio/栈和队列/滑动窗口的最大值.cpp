#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class MyQueue
{
public:
    deque<int> que;

    void pop(int val)
    {
        if (!que.empty() && val == que.front())
        {
            que.pop_front();
        }
    }

    void push(int val)
    {
        while (!que.empty() && val > que.back())
        {
            que.pop_back();
        }
        que.push_back(val);
    }

    int front()
    {
        return que.front();
    }
};

vector<int> maxWindow(vector<int>& nums, int k)
{
    MyQueue que;
    vector<int> result;

    for (int i = 0; i < k; i++)
    {
        que.push(nums[i]);
    }
    result.push_back(que.front());

    for (int i = k; i < nums.size(); i++)
    {
        que.pop(nums[i - k]);
        que.push(nums[i]);
        result.push_back(que.front());
    }

    return result;
}
//
//int main()
//{
//    int k = 3;
//
//    vector<int> s;
//    s.push_back(1);
//    s.push_back(3);
//    s.push_back(-1);
//    s.push_back(-3);
//    s.push_back(5);
//    s.push_back(3);
//    s.push_back(2);
//    s.push_back(1);
//
//    vector<int>ret = maxWindow(s, k);
//    for (int i = 0; i < ret.size(); i++)
//    {
//        cout << ret[i] << " ";
//    }
//    cout << endl;
//    system("pause");
//    return 0;
//}