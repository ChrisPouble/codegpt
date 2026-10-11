#include <bits/stdc++.h>
using namespace std;

#define mkp make_pair

using pii = pair<int, int>;

const int N = 1e6 + 10;
const pii inf = mkp(1e9 + 10, 1e6 + 10);
const pii ind = mkp(-1e9 - 10, 0);

int n, a[N];

pii q1[N], q2[N]; // 维护时保证两个队列单增 
int hd1, tl1, hd2, tl2;

int add(int x) { if (++x == N) x = 0; return x; }
int sub(int x) { if (--x == -1) x = N - 1; return x; }
pii mx1() { return sub(hd1) != tl1 ? q1[tl1] : ind; }
pii mn1() { return sub(hd1) != tl1 ? q1[hd1] : inf; }
pii mx2() { return sub(hd2) != tl2 ? q2[tl2] : ind; }
pii mn2() { return sub(hd2) != tl2 ? q2[hd2] : inf; }

int solve() {
	hd1 = hd2 = 0, tl1 = tl2 = N - 1; // 初始化循环队列

	int num = n; // num: 记录第一阶段结束时，实际剩余的蛇的数量 
    int sum = n; // sum: 循环中的总蛇数，每发生一次吞噬 sum--
	for (int i = 1; i <= n; i++)
        q1[tl1 = add(tl1)] = mkp(a[i], i); // 将排好序的蛇压入 q1
	
    int flag = 0; // 是否进入第二阶段 (0表示否，1表示是)
    int cur = 0;  // 博弈链的奇偶性标记
    
	while (sum >= 2) { // 场上至少还有2条蛇
        // 1. 取出全场最强的蛇 mx
		pii mx, mn;
		if (mx1() < mx2()) mx = mx2(), tl2 = sub(tl2); // q2队尾更大，弹出q2队尾
		else mx = mx1(), tl1 = sub(tl1);               // 否则弹出q1队尾

        // 2. 取出全场最弱的蛇 mn
		if (mn1() > mn2()) mn = mn2(), hd2 = add(hd2); // q2队首更小，弹出q2队首
		else mn = mn1(), hd1 = add(hd1);               // 否则弹出q1队首
	
        // 3. 模拟吞噬
		mx.first -= mn.first, sum--; 
		
        // 4. 博弈状态机（全题最核心部分）
        // 判断条件: 新产生的蛇(mx) 是否比 场上剩下蛇中的最小值(min(mn1, mn2)) 还要弱？
		if (sum >= 2 && mx < min(mn1(), mn2())) {
            // 情况A：新蛇变成了全场最弱，游戏进入【第二阶段：生死博弈链】
			if (flag) cur ^= 1; // 如果已经在第二阶段了，只切换奇偶性状态
			else flag = 1;      // 如果刚进入第二阶段，标记 flag = 1，此时 cur 仍为 0
		}
		else {
            // 情况B：新蛇没有变成最弱，或者这是全场最后一次吞噬（sum < 2）
			if (flag) {
                // 如果之前已经进入了第二阶段，说明生死博弈链在这里断裂了！
                // 这说明此时决定吃蛇的这条蛇，吃完不仅不会死，还很安全。
                // 倒推回去：最后这条安全的蛇打破了僵局，根据 cur 的奇偶性，
                // 可以直接得出第一条引起博弈链的蛇到底该不该吃。
                return num - cur; 
            }
            // 如果还在第一阶段（安全期），真实存活蛇数量减1
			num--;
		}
		
        // 5. 将新产生的蛇放入 q2 的头部 (因为数值越来越小，放头部正好保持从小到大的单调性)
        q2[hd2 = sub(hd2)] = mx;
	}

	return num;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int T; cin >> T;
	for (int i = 1; i <= T; i++) {
		if (i == 1) {
			cin >> n;
			for (int j = 1; j <= n; j++)
                cin >> a[j];
		}
		else {
			int k; cin >> k;
			for (int j = 1; j <= k; j++) {
                int id, x; cin >> id >> x;
                a[id] = x;
            }
		}
		
        cout << solve() << "\n";
	}

	return 0;
}