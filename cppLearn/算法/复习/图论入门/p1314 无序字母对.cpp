//#include <iostream>
//using namespace std;
//
///*先要把所有字母列举出来
//  再把字母之间的关系弄出来
//  a  t
//  |\/|
//  |/\|
//  X  Z
//  最后再看看从ASCII码值最小的那个字母开始能否一笔画
//  能就输出过程
//  不能就输出NO Sulution
//*/
//
//int n, now = 0, a[150], tot = 0;
//bool is_input[150], G[150][150], vis[150][150];
//void dfs(int x) {
//    if (now == n) {
//        for (int i = 1; i <= tot; i++)
//            cout << char(a[i]);
//        exit(0);
//    }
//
//    for (int i = 'A'; i <= 'z'; i++)
//        if (G[x][i] && !vis[x][i]) {
//            now++;
//            tot++;
//            vis[x][i] = vis[i][x] = true;
//            a[tot] = i;
//            dfs(i);
//            --now;
//            --tot;
//            vis[x][i] = vis[i][x] = false;
//        }
//}
//
//int main() {
//    string s; cin >> n;
//    for (int i = 1; i <= n; i++) {
//        cin >> s;
//        if (!is_input[s[0]]) is_input[s[0]] = true;
//        if (!is_input[s[1]]) is_input[s[1]] = true;
//        G[s[0]][s[1]] = G[s[1]][s[0]] = true;
//    }
//    for (int i = 'A'; i <= 'z'; i++)
//        if (is_input[i]) {
//            a[++tot] = i;
//            dfs(i);
//            break;
//        }
//    cout << "NO Sulution" << endl;
//    return 0;
//}