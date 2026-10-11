#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

class mycomparison {
public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
        return lhs.second > rhs.second;
    }
};

vector<int> findK(vector<int>& nums, int k)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) 
        map[nums[i]]++;
    
    //定义一个小顶堆, 大小为k
    priority_queue<pair<int, int>, vector<pair<int, int>>,
    mycomparison> pri_que;

    for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
        pri_que.push(*it);
        if (pri_que.size() > k) pri_que.pop();
    }

    vector<int> result(k);
    for (int i = k - 1; i >= 0; i--) {
        result[i] = pri_que.top().first;
        pri_que.pop();
    }
    return result;
} 

int main()
{
    int k = 2;

    vector<int> s;
    s.push_back(1);
    s.push_back(1);
    s.push_back(1);
    s.push_back(3);
    s.push_back(2);
    s.push_back(3);
    s.push_back(2);
    s.push_back(1);

    vector<int>ret = findK(s, k);
    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}