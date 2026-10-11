#include<bits/stdc++.h>
using namespace std;

struct game{
    int sum, id;
};

bool operator<(game a, game b) {
    if(a.sum > b.sum) return true;
    else return false;
}

priority_queue<game>q;
long long x, y;
int a[100010], b[100010];
int main() {
    freopen("brick.in","r",stdin);
    freopen("brick.out","w",stdout);
    int n, cnt = 0; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        if(a[i] > b[i]) {
            cnt++;
            game temp;
            temp.sum = a[i], temp.id = i;
            q.push(temp);
        }
    }
    for (int i = 1; i <= cnt; i++) {
        game t1 = q.top();
        x += t1.sum; q.pop();
        q.push({b[t1.id], t1.id});
        game t2 = q.top();
        y += t2.sum; q.pop();
        q.push({b[t2.id], t2.id});
    }
    cout << x - y << endl;
    return 0;
}
/*
2
2 1
4 3
*/