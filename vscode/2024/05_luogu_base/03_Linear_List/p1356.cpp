#include <iostream>
#include <vector>
using namespace std;

int n, m, tmp;
int main() {
    vector<int>stu; //建立一个一维可变数组
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        stu.push_back(tmp); //把学生按照顺序加入到数组中
    }
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        cout << stu[tmp - 1] << endl;
    }
    return 0;
}