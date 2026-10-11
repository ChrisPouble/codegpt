#include <bits/stdc++.h>
#define maxn 100010
#define int long long 
using namespace std;
namespace Fastio
{
    struct Reader
    {
        template <typename T> Reader& operator >> (T &x)
        {
            x = 0;
            short f = 1;
            char c = getchar();
            while (c < '0' || c > '9') { if (c == '-') f *= -1; c = getchar(); }
            while (c >= '0' && c <= '9') x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
            x *= f;
            return *this;
        }
        Reader& operator >> (double &x)
        {
            x = 0;
            double t = 0;
            short f = 1, s = 0;
            char c = getchar();
            while ((c < '0' || c > '9') && c != '.') { if (c == '-') f *= -1; c = getchar(); }
            while (c >= '0' && c <= '9' && c != '.') x = x * 10 + (c ^ 48), c = getchar();
            if (c == '.') c = getchar();
            else { x *= f; return *this; }
            while (c >= '0' && c <= '9') t = t * 10 + (c ^ 48), s++, c = getchar();
            while (s--) t /= 10.0;
            x = (x + t) * f;
            return *this;
        }
        Reader& operator >> (long double &x)
        {
            x = 0;
            long double t = 0;
            short f = 1, s = 0;
            char c = getchar();
            while ((c < '0' || c > '9') && c != '.') { if (c == '-') f *= -1; c = getchar(); }
            while (c >= '0' && c <= '9' && c != '.') x = x * 10 + (c ^ 48), c = getchar();
            if (c == '.') c = getchar();
            else { x *= f; return *this; }
            while (c >= '0' && c <= '9') t = t * 10 + (c ^ 48), s++, c = getchar();
            while (s--) t /= 10.0;
            x = (x + t) * f;
            return *this;
        }
        Reader& operator >> (__float128 &x)
        {
            x = 0;
            __float128 t = 0;
            short f = 1, s = 0;
            char c = getchar();
            while ((c < '0' || c > '9') && c != '.') { if (c == '-') f *= -1; c = getchar(); }
            while (c >= '0' && c <= '9' && c != '.') x = x * 10 + (c ^ 48), c = getchar();
            if (c == '.') c = getchar();
            else { x *= f; return *this; }
            while (c >= '0' && c <= '9') t = t * 10 + (c ^ 48), s++, c = getchar();
            while (s--) t /= 10.0;
            x = (x + t) * f;
            return *this;
        }
        Reader& operator >> (char &c)
        {
            c = getchar();
            while (c == ' ' || c == '\n' || c == '\r') c = getchar();
            return *this;
        }
        Reader& operator >> (char *str)
        {
            int len = 0;
            char c = getchar();
            while (c == ' ' || c == '\n' || c == '\r') c = getchar();
            while (c != ' ' && c != '\n' && c != '\r') str[len++] = c, c = getchar();
            str[len] = '\0';
            return *this;
        }
        Reader& operator >> (string &str)
        {
            str.clear();
            char c = getchar();
            while (c == ' ' || c == '\n' || c == '\r') c = getchar();
            while (c != ' ' && c != '\n' && c != '\r') str.push_back(c), c = getchar();
            return *this;
        }
        Reader() {}
    } cin;
    const char endl = '\n';
    struct Writer
    {
        const int Setprecision = 6;
        typedef int mxdouble;
        template <typename T> Writer& operator << (T x)
        {
            if (x == 0) { putchar('0'); return *this; }
            if (x < 0) putchar('-'), x = -x;
            static short sta[40];
            short top = 0;
            while (x > 0) sta[++top] = x % 10, x /= 10;
            while (top > 0) putchar(sta[top] + '0'), top--;
            return *this;
        }
        Writer& operator << (double x)
        {
            if (x < 0) putchar('-'), x = -x;
            mxdouble _ = x;
            x -= (double)_;
            static short sta[40];
            short top = 0;
            while (_ > 0) sta[++top] = _ % 10, _ /= 10;
            if (top == 0) putchar('0');
            while (top > 0) putchar(sta[top] + '0'), top--;
            putchar('.');
            for (int i = 0; i < Setprecision; i++) x *= 10;
            _ = x;
            while (_ > 0) sta[++top] = _ % 10, _ /= 10;
            for (int i = 0; i < Setprecision - top; i++) putchar('0');
            while (top > 0) putchar(sta[top] + '0'), top--;
            return *this;
        }
        Writer& operator << (long double x)
        {
            if (x < 0) putchar('-'), x = -x;
            mxdouble _ = x;
            x -= (long double)_;
            static short sta[40];
            short top = 0;
            while (_ > 0) sta[++top] = _ % 10, _ /= 10;
            if (top == 0) putchar('0');
            while (top > 0) putchar(sta[top] + '0'), top--;
            putchar('.');
            for (int i = 0; i < Setprecision; i++) x *= 10;
            _ = x;
            while (_ > 0) sta[++top] = _ % 10, _ /= 10;
            for (int i = 0; i < Setprecision - top; i++) putchar('0');
            while (top > 0) putchar(sta[top] + '0'), top--;
            return *this;
        }
        Writer& operator << (__float128 x)
        {
            if (x < 0) putchar('-'), x = -x;
            mxdouble _ = x;
            x -= (__float128)_;
            static short sta[40];
            short top = 0;
            while (_ > 0) sta[++top] = _ % 10, _ /= 10;
            if (top == 0) putchar('0');
            while (top > 0) putchar(sta[top] + '0'), top--;
            putchar('.');
            for (int i = 0; i < Setprecision; i++) x *= 10;
            _ = x;
            while (_ > 0) sta[++top] = _ % 10, _ /= 10;
            for (int i = 0; i < Setprecision - top; i++) putchar('0');
            while (top > 0) putchar(sta[top] + '0'), top--;
            return *this;
        }
        Writer& operator << (char c) { putchar(c); return *this; }
        Writer& operator << (char *str)
        {
            int cur = 0;
            while (str[cur]) putchar(str[cur++]);
            return *this;
        }
        Writer& operator << (const char *str)
        {
            int cur = 0;
            while (str[cur]) putchar(str[cur++]);
            return *this;
        }
        Writer& operator << (string str)
        {
            int st = 0, ed = str.size();
            while (st < ed) putchar(str[st++]);
            return *this;
        }
        Writer() {}
    } cout;
}
using namespace Fastio;
#define cin Fastio::cin
#define cout Fastio::cout
#define endl Fastio::endl

int n, m, root, P, cnt;
int w[maxn], sumv[4 * maxn], lazy[4 * maxn];
int fa[maxn], dep[maxn], son[maxn], sz[maxn]; //父亲节点，节点深度，重儿子、子树大小 
int top[maxn], id[maxn], nw[maxn]; //树链链头，dfs序节点编号、新点权 
vector<int>linker[maxn];
void pushup(int id) {
	sumv[id] = sumv[id * 2] + sumv[id * 2 + 1];
}

void pushdown(int id, int l, int r) {
	if(lazy[id] != 0) {
		int mid = (l + r) >> 1;
		sumv[id * 2] = sumv[id * 2] + lazy[id] * (mid - l + 1);
		sumv[id * 2 + 1] = sumv[id * 2 + 1] + lazy[id] * (r - mid);
		lazy[id * 2] += lazy[id];
		lazy[id * 2 + 1] += lazy[id];
		lazy[id] = 0;
	}
}

void build(int id, int l, int r) {
	if(l == r) {
		sumv[id] = nw[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(id * 2, l, mid);
	build(id * 2 + 1, mid + 1, r);
	pushup(id);
}

void update(int id, int l, int r, int x, int y, int v) {
	if(x <= l && r <= y) {
		sumv[id] = sumv[id] + v * (r - l + 1);
		lazy[id] = lazy[id] + v;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(id, l, r);
	if(x <= mid) update(id * 2, l, mid, x, y, v);
	if(y > mid) update(id * 2 + 1, mid + 1, r, x, y, v);
	pushup(id);
}

int query(int id, int l, int r, int x, int y) {
	if(x <= l && r <= y) return sumv[id];
	int mid = (l + r) >> 1, ans = 0;
	pushdown(id, l, r);
	if(x <= mid) ans += query(id * 2, l, mid, x, y);
	if(y > mid) ans += query(id * 2 + 1, mid + 1, r, x, y);
	return ans;
}

void dfs1(int x, int father) {
	fa[x] = father, dep[x] = dep[father] + 1, sz[x] = 1;
	for (auto v:linker[x]) {
		if(v == father) continue; 
		dfs1(v, x);
		sz[x] += sz[v];
		if(sz[son[x]] < sz[v]) son[x] = v;
	}
}

void dfs2(int x, int t) { //t是指top 
	top[x] = t, id[x] = ++cnt, nw[cnt] = w[x];
	if(!son[x]) return;
	dfs2(son[x], t);
	for (auto v:linker[x]) {
		if(v == fa[x] || v == son[x]) continue;
		dfs2(v, v);
	}
}

int query_path(int x, int y) {
	int res = 0;
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		res += query(1, 1, n, id[top[x]], id[x]);
		x = fa[top[x]];
	}
	if(dep[x] < dep[y]) swap(x, y);
	res += query(1, 1, n, id[y], id[x]);
	return res;
}

void update_path(int x, int y, int k) {
	while(top[x] != top[y]) {
		if(dep[top[x]] < dep[top[y]]) swap(x, y);
		update(1, 1, n, id[top[x]], id[x], k);
		x = fa[top[x]];
	}
	if(dep[x] < dep[y]) swap(x, y);
	update(1, 1, n, id[y], id[x], k);
}

int query_tree(int x) {
	return query(1, 1, n, id[x], id[x] + sz[x] - 1);
}

void update_tree(int x, int k) {
	update(1, 1, n, id[x], id[x] + sz[x] - 1, k);
}

void add(int x, int y) {
	linker[x].push_back(y);
}

signed main() {
	cin >> n >> m >> root >> P;
	for (int i = 1; i <= n; i++) cin >> w[i]; 
	for (int i = 1, x, y; i < n; i++) {
		cin >> x >> y;
		add(x, y), add(y, x);
	}
	dfs1(root, 0), dfs2(root, root);
	build(1, 1, n);
	while(m--) {
		int opt, x, y, z;
		cin >> opt;
		if(opt == 1) {
			cin >> x >> y >> z;
			update_path(x, y, z);
		}
		if(opt == 2) {
			cin >> x >> y;
			cout << query_path(x, y) % P << endl;
		}
		if(opt == 3) {
			cin >> x >> z;
			update_tree(x, z);
		}
		if(opt == 4) {
			cin >> x;
			cout << query_tree(x) % P << endl;
		}
	}
	return 0;
}
