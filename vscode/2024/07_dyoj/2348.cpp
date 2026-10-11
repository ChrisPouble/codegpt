#include <bits/stdc++.h>
using namespace std;

int n, ans, flag[21];
string a[21];
char ch;
string add(string x, string y) {
    string str = ""; //记录重复字符串
    bool is = true; //是否有重复字符串
    for (int i = x.size() - 1; i >= 0; i--) { //越早找到字符串越好
        str += x[i]; //加上
        if(str.size() > y.size()) break; //如果超过了y的长度，说明不可能再有重复字符串了
        is = true; //先记录
        for (int j = 0, k = str.size() - 1; j < str.size(); j++, k--) //看看重复字符串str是否合格
            if(str[j] != y[k]) { //如果不可以
                is = false; //则记录
                break; //并退出
            }
        if(is) break; //如果没有进入上面循环中的if语句，则说明这个字符串可以，并退出
    }
    //if(!is) str = ""; //如果没有重复字符串
    if(!is || str.size() == y.size()) return "I_AK_IOI"; //如果没有重复字符串或者被覆盖了，则返回一个不可能出现的字符串
    string res = "";
    for (int k = 0; k < x.size(); k++) res += x[k]; //否则把x和y之间记录下来，并且不要重复字符串的那部分
    for (int k = str.size(); k < y.size(); k++) res += y[k];
    return res;
}

void dfs(string s) {
    bool isLast = 0;
    for (int i = 1; i <= n; i++)
        if (flag[i] < 2) { //如果单词使用次数小于2，则说明可以使用
            string x = add(s, a[i]); //获取接龙后的字符串
            if(x != "I_AK_IOI") { //如果接龙成功
                isLast = 1;
                flag[i]++; //则使用次数增加
                dfs(x); //并且接着找
                flag[i]--; //恢复现场
            }
        }
    if (!isLast) ans = max(ans, (int)s.size()); //如果后面没有接过龙，则说明该记录答案了
}

int main() {
    cin >> n;
    getchar();
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> ch;
    for (int i = 1; i <= n; i++)
        if (a[i][0] == ch) {
            memset(flag, 0, sizeof(flag)); //又是新一轮的循环
            flag[i]++; //第i个字符串的使用次数+1
            dfs(a[i]); //接着去找
            flag[i]--; //其实这一行代码可以不用，因为下一次要memset
        }
    cout << ans << endl;
    return 0;
}