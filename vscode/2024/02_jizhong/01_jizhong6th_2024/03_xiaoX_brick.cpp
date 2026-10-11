#include <bits/stdc++.h>
using namespace std;

// int x, y;
long long all_x[2]={0};
long long tmp_x[2]={0};
struct Brick {
    int num, color;
}a[100010];

int main() {
    freopen("brick.in","r",stdin);
    freopen("brick.out","w",stdout);
    int n, ans = 0; cin >> n;
    // for (int i = 1; i <= n; i++) {
    //     int num, temp_color; cin >> num >> temp_color;
    //     a[i].num = num, a[i].color = temp_color;
    //     if(temp_color == 0) x += num;
    //     else y += num;
    // }
    // int tx = 0, ty = 0;
    // for (int i = 1; i <= n; i++) {
    //     if (a[i].color == 0) tx += a[i].num;
    //     else ty += a[i].num;
    //     if(tx == 0 || ty == 0) continue;
    //     if(a[i].color == 0) {
    //         if(x * ty % y == 0) {
    //             int temp = x * ty / y;
    //             if(tx >= temp) ans++, ty = 0, tx -= temp;
    //         }
    //     } else {
    //             if(y * tx % x == 0) {
    //             int temp = y * tx / x;
    //             if(ty >= temp) ans++, tx = 0, ty -= temp;
    //         }
    //     }
    // }
    // 知识点1：比例是固定的，每个分块的比例如果都相同，那么这个比例和总数的比例一致，所以求总数的比例就行了
    for (int i = 1; i <= n; i++) {
        int num, temp_color; cin >> num >> temp_color;
        a[i].num = num, a[i].color = temp_color;
        all_x[temp_color]+=num;
    }
    
    for (int i = 1; i <= n; i++)
    {
        int color=a[i].color,other_color=!color;
        tmp_x[color]+=a[i].num;

        //all_x[color]/all_x[other_color]=tmp_x[color]/tmp_x[other_color]=>
        // all_x[color]*tmp_x[other_color]/all_x[other_color]
        // 知识点2：计算机不擅长除法，改用取余后乘法验证
        if (tmp_x[other_color]&&all_x[color]*tmp_x[other_color]%all_x[other_color]== 0)
        {
            int temp = all_x[color]*tmp_x[other_color]/all_x[other_color];
            if (tmp_x[color] >= temp)
                ans++;//知识点3：这里不用对已经遍历的数量进行清零
        }
    }

    cout << ans << endl;
    return 0;
}

/*
//暴力解法
#include <iostream>
using namespace std;

char s[100010];
int n, ans = 1, y = 0;
struct bw {
   int black;
   int white;
}t[100010];

bool bili(int a, int b, int c, int d) {
   if (a * d != b * c) return false;
   return true;
}

void dg(int x, int len) {
   if (x == y) {
       if (len == 1) {
            ans = max(len, ans);
            return;
       }
       for (int i = 0; i < len; i++) {
           int fb = t[i].black, fw = t[i].white;
           int gb = t[i + 1].black, gw = t[i + 1].white;
           if (!bili(fw, fb, gw, gb)) return;
       }
       ans = max(len, ans);
   }
   for (int i = 1; i <= y - x; i++) {
       for (int j = 1; j <= i; j++)
           if (s[j + x] == '1') t[len].black++;
           else t[len].white++;
       dg(x + i, len + 1);
       t[len].black = t[len].white = 0;
   }
}

int main() {
   cin >> n;
   for (int i = 0; i < n; i++) {
       int num; char z; cin >> num >> z;
       for (int j = 0; j < num; j++) {
           s[y] = z;
           y++;
       }
   }
   y--;
   dg(-1, 0);
   cout << ans << endl;
   return 0;
}*/
/*
6
1 1
4 0
1 1
1 0
1 1
1 0
*/
