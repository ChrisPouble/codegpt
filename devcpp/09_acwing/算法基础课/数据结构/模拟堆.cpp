#include <bits/stdc++.h>
#define maxn 100010
using namespace std;

int n, m, cnt, has[maxn], ph[maxn], hp[maxn]; //ph表示从idx映射到下标，hp则反之
void new_swap(int x, int y) {
    swap(has[x], has[y]); //首先，值换了
    swap(ph[hp[x]], ph[hp[y]]); //其次，代表的下标换了
    swap(hp[x], hp[y]); //最后，映射到的idx换了
}

void insert(int k) {
    while(k > 1 && has[k] < has[k / 2]) {
    	new_swap(k, k / 2);
    	k /= 2;
	}
}

void pop(int k) {
    int t = k;
    if(k * 2 <= cnt && has[k * 2] < has[t]) t = k * 2;
    if(k * 2 + 1 <= cnt && has[k * 2 + 1] < has[t]) t = k * 2 + 1;
    if(k != t) {
        new_swap(k, t);
        pop(t);
    }
} 

int main() {
    cin >> n;
    while(n--) {
        string opt;
        int x, y;
        cin >> opt;
        if(opt == "I") {
            cin >> x;
            cnt++, m++; //cnt指下标，m指idx
            ph[m] = cnt, hp[cnt] = m;
            has[cnt] = x;
            insert(cnt);
        }
        else if(opt == "PM") cout << has[1] << "\n";
        else if(opt == "DM") {
            new_swap(cnt, 1);
            cnt--;
            pop(1);
        }
        else if(opt == "D") {
            cin >> x;
            int k = ph[x]; //映射到下标
            new_swap(k, cnt--);
            insert(k), pop(k); //这里的insert与pop只是为了使这个堆有序，并非插入或删除
        }
        else if(opt == "C") {
            cin >> x >> y;
            int k = ph[x];
            has[k] = y;
            insert(k), pop(k); //这里的insert与pop只是为了使这个堆有序，并非插入或删除
        }
    }
    return 0;
}
