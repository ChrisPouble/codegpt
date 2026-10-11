#include <bits/stdc++.h>
using namespace std;

int n = 6, a[1010];
bool f[1010][1010];
bool dg(int size, int s)
{
    bool result;
    if (s == 0)
        return true;
    
    if(size == 0) {
        if(a[size] == s) return true;
        else return false;
    }

    if (a[size] > s)
        result = dg(size - 1, s);
    else
        result = dg(size - 1, s) || dg(size - 1, s - a[size]);
    cout << size << " " << s << endl;
    f[size][s] = result;
    return result;
}

int dp(int n, int s)
{
    for (int i = 1; i <= n; i++)
        f[i][0] = true;
    f[1][a[1]] = true;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (a[i] > j)
                f[i][j] = f[i - 1][j];
            else
                f[i][j] = f[i - 1][j] || f[i - 1][j - a[i]];
        }
    }
    return f[n][s];
}

int main()
{
    int s;
    cin >> n >> s;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (dg(n - 1, s))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            cout << f[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}
/*
6 9 3 34 4 12 5 2
*/