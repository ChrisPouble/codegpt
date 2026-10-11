#include <bits/stdc++.h>
#define M 998244353  // 模数（本题未实际使用）
using namespace std;

// 全局变量声明（1-based 索引，适配输入习惯）
int T, n, m, d, tx;
int x[200005], y[200005];          // 输入：x[i]是第i行最大值，y[j]是第j列最大值
int ans[200005];                   // 结果矩阵（行优先存储：(i-1)*m + j 对应第i行第j列）
int p[200005], q[200005];          // 映射：p[v]=i表示v是第i行最大值，q[v]=j表示v是第j列最大值
int nxtx[200005], prvx[200005];    // 行双向链表：nxtx[i]是i的下一个行，prvx[i]是i的前一个行
int nxty[200005], prvy[200005];    // 列双向链表：nxty[j]是j的下一个列，prvy[j]是j的前一个列
int cx[200005], cy[200005];        // 树状数组：维护已处理行/列的最大值，辅助链表插入
bool sp[200005], sq[200005];       // 标记：sp[i]=1表示第i行最大值已放置，sq[j]=1同理
queue<int> qe;                     // 缓存待填充的安全位置
bool c, k;                         // 状态标记：c=1表示无法构造，k临时判断是否找到合法位置

// 行处理：将行x插入双向链表（用树状数组cx快速找插入位置）
void addx(int x) {
    d = 0;
    // 树状数组查询：找到已处理行中的最大值（插入位置的前驱）
    for (int i = x; i > 0; i -= (i & -i)) {
        d = max(d, cx[i]);
    }
    // 双向链表插入：将x插入到d之后
    prvx[x] = d;
    nxtx[x] = nxtx[d];
    prvx[nxtx[d]] = x;
    nxtx[d] = x;
    // 树状数组更新：维护已处理行的最大值
    for (int i = x; i <= n; i += (i & -i)) {
        cx[i] = max(cx[i], x);
    }
}

// 列处理：将列x插入双向链表（逻辑与addx一致，用树状数组cy）
void addy(int x) {
    d = 0;
    // 树状数组查询：找到已处理列中的最大值（插入位置的前驱）
    for (int i = x; i > 0; i -= (i & -i)) {
        d = max(d, cy[i]);
    }
    // 双向链表插入：将x插入到d之后
    prvy[x] = d;
    nxty[x] = nxty[d];
    prvy[nxty[d]] = x;
    nxty[d] = x;
    // 树状数组更新：维护已处理列的最大值
    for (int i = x; i <= m; i += (i & -i)) {
        cy[i] = max(cy[i], x);
    }
}

int main() {
    // 输入输出加速（关闭同步，解除cin与stdio绑定）
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> T;
    while (T--) {
        cin >> n >> m;

        // 初始化行相关数据
        for (int i = 1; i <= n; i++) {
            cin >> x[i];
            p[x[i]] = i;  // 建立“值->行”映射
            cx[i] = 0;    // 树状数组清零
        }

        // 初始化列相关数据
        for (int i = 1; i <= m; i++) {
            cin >> y[i];
            q[y[i]] = i;  // 建立“值->列”映射
            cy[i] = 0;    // 树状数组清零
        }

        c = false;  // 初始化：默认可以构造
        // 双向链表哨兵初始化（0为头哨兵，n+1/m+1为尾哨兵）
        nxtx[0] = n + 1;
        nxty[0] = m + 1;
        prvx[n + 1] = 0;
        prvy[m + 1] = 0;

        // 核心逻辑：从大到小放置元素（保证行/列最大值优先级）
        for (int i = n * m; i >= 1; i--) {
            if (p[i] && q[i]) {
                // 情况1：i既是行最大值，也是列最大值（如全局最大值n*m）
                sp[p[i]] = true;  // 标记该行最大值已放置
                sq[q[i]] = true;  // 标记该列最大值已放置
                // 放置i到行p[i]、列q[i]的交点
                ans[(p[i] - 1) * m + q[i]] = i;

                // 收集“已处理行”与当前列q[i]的交点，加入待填充队列
                for (int j = nxtx[0]; j != n + 1; j = nxtx[j]) {
                    qe.push((j - 1) * m + q[i]);
                }
                // 收集“已处理列”与当前行p[i]的交点，加入待填充队列
                for (int j = nxty[0]; j != m + 1; j = nxty[j]) {
                    qe.push((p[i] - 1) * m + j);
                }

                // 将当前行、列插入双向链表
                addx(p[i]);
                addy(q[i]);
            }
            else if (p[i]) {
                // 情况2：i仅是行最大值，不是列最大值
                sp[p[i]] = true;  // 标记该行最大值已放置
                k = true;         // 临时标记：是否找到合法位置

                // 遍历已处理列（列最大值已放置，且比i大），找一个列放置i
                for (int j = nxty[0]; j != m + 1; j = nxty[j]) {
                    if (sq[j]) {
                        ans[(p[i] - 1) * m + j] = i;
                        k = false;  // 找到位置，标记为false
                        break;
                    }
                }

                if (k) {
                    c = true;  // 没找到位置，无法构造
                    break;
                }

                // 将当前行插入双向链表
                addx(p[i]);
                // 收集当前行与已处理列的交点，加入待填充队列
                for (int j = nxty[0]; j != m + 1; j = nxty[j]) {
                    qe.push((p[i] - 1) * m + j);
                }
            }
            else if (q[i]) {
                // 情况3：i仅是列最大值，不是行最大值（与情况2对称）
                sq[q[i]] = true;  // 标记该列最大值已放置
                k = true;         // 临时标记：是否找到合法位置

                // 遍历已处理行（行最大值已放置，且比i大），找一个行放置i
                for (int j = nxtx[0]; j != n + 1; j = nxtx[j]) {
                    if (sp[j]) {
                        ans[(j - 1) * m + q[i]] = i;
                        k = false;  // 找到位置，标记为false
                        break;
                    }
                }

                if (k) {
                    c = true;  // 没找到位置，无法构造
                    break;
                }

                // 将当前列插入双向链表
                addy(q[i]);
                // 收集当前列与已处理行的交点，加入待填充队列
                for (int j = nxtx[0]; j != n + 1; j = nxtx[j]) {
                    qe.push((j - 1) * m + q[i]);
                }
            }
            else {
                // 情况4：i是普通元素（非行/列最大值）
                k = true;  // 临时标记：是否找到合法位置

                // 从队列取待填充位置，放置i
                while (!qe.empty()) {
                    tx = qe.front();
                    qe.pop();
                    if (!ans[tx]) {  // 位置未被填充
                        ans[tx] = i;
                        k = false;  // 找到位置，标记为false
                        break;
                    }
                }

                if (k) {
                    c = true;  // 没找到位置，无法构造
                    break;
                }
            }
        }

        // 清空队列（避免影响下一个测试用例）
        while (!qe.empty()) {
            qe.pop();
        }

        if (c) {
            // 无法构造，输出No
            cout << "No" << endl;
        }
        else {
            // 可以构造，输出Yes和矩阵
            cout << "Yes" << endl;
            for (int i = 1; i <= n * m; i++) {
                cout << ans[i] << ' ';
                if (i % m == 0) {  // 每行m个元素，换行
                    cout << endl;
                }
            }
        }

        // 重置全局变量（避免影响下一个测试用例）
        for (int i = 1; i <= n * m; i++) {
            ans[i] = 0;
            p[i] = 0;
            q[i] = 0;
            sp[i] = false;
            sq[i] = false;
        }
    }

    return 0;
}