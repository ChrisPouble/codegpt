#include <bits/stdc++.h>
using namespace std;

int len, dp[1010][1010];
char s[1010], t[1010];
int main() {
    scanf("%s", s + 1);
    len = strlen(s + 1);
    for (int i = 1; i <= len; i++)
        t[i] = s[len - i + 1];
    for (int i = 1; i <= len; i++)
        for (int j = 1; j <= len; j++)
            if(s[i] == t[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    printf("%d", len - dp[len][len]);
    return 0;
}