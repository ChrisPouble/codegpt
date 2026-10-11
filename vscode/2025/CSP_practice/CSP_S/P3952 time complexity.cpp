#include <bits/stdc++.h>
using namespace std;

const int N = 110;

string codes[N];

// 将字符串转化为数字
int work(string x) {
    int sum = 0;
    for (auto v : x)
        sum = sum * 10 + (v - '0');
    return sum;
}

string change(int x) {
    string ans = "";
    while (x) {
        ans = ((char)(x % 10 + 48)) + ans;
        x /= 10;
    }
    return ans;
}

int get(string x, string y) { // 判断循环下界与上界所构成的循环的时间复杂度
    if (x == "n" && y == "n") return 0;
    else if (x == "n") return -1;
    else if (y == "n") return 1;
    else if (work(x) <= work(y)) return 0;
    else return -1;
}

string solve(int n) {
    int ans = 0;
    stack<int> stk;
    map<string, bool> vis;
    vector<string> vec;

    for (int i = 1; i <= n; i++) {
        string str = codes[i] + " ";

        if (str[0] == 'F') {
            int k = 2;
            string val = "", sta = "", en = "";

            for (k = 2; str[k] != ' '; k ++) val += str[k];
            for (k ++; str[k] != ' '; k ++) sta += str[k];
            for (k ++; str[k] != ' '; k ++) en += str[k];

            if (vis[val] == 1) return "ERR";
            vec.push_back(val), vis[val] = 1;
            
            int res = get(sta, en);
            
            if (stk.empty()) stk.push(res), ans = max(ans, res);
            else {
                int top = stk.top();
                if (top == -1 || res == -1) stk.push(-1);
                else stk.push(top + res), ans = max(ans, top + res);
            }
        } else {
            if (stk.empty()) return "ERR";
            stk.pop();
            vis[vec.back()] = 0;
            vec.pop_back();
        }
    }

    if (vec.size() != 0) return "ERR";

    if (ans == 0) return "O(1)";
    else return "O(n^" + change(ans) + ")";
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        string str;

        cin >> n >> str;

        getchar();

        for (int i = 1; i <= n; i++)
            getline(cin, codes[i]);

        string res = solve(n);

        if (res == "ERR") cout << res << "\n";
        else if (res == str) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}