#include <bits/stdc++.h>
using namespace std;

int k, sum, m, b[80];
char d[20];
string n, ans;
stack<char>st;
void csh() {
    for (char i = '0'; i <= '9'; i++)
        b[(int)i] = i - 48;
    for (char i = 'A'; i <= 'F'; i++)
        b[(int)i] = i - 55;
    for (int i = 0; i <= 9; i++)
        d[i] = i + 48;
    for (int i = 10; i <= 15; i++)
        d[i] = i + 55;
}

int main() {
    cin >> k >> n >> m;
    csh(); //初始化
    for (int i = n.size() - 1, j = 0; i >= 0; i--, j++)
        sum += b[n[i]] * pow(k, j); //转成十进制
    while(sum) { //转成m进制
        st.push(d[sum % m]);
        sum /= m;
    }
    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
    cout << ans << endl;
    return 0;
}