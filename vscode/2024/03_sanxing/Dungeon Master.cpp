#include <iostream>
#include <queue>
using namespace std;
char a[55][55][55], dx[6] = {-1, 0, 0, 0, 0, 1}, dy[6] = {0, 1, -1, 0, 0, 0}, dz[6] = {0, 0, 0, 1, -1, 0};
int ceng, chang, kuan; // 层数，长数， 宽数

struct zb
{
    int x, y, z, sum;
};
int main()
{
    while (1)
    {
        cin >> ceng >> chang >> kuan;
        if (ceng == 0 && chang == 0 && kuan == 0)
            break;
        int si, sj, sk, ei, ej, ek;
        for (int i = 1; i <= ceng; i++)
        {
            for (int j = 1; j <= chang; j++)
            {
                for (int k = 1; k <= kuan; k++)
                {
                    cin >> a[i][j][k];
                    if (a[i][j][k] == 'S')
                        si = i, sj = j, sk = k;
                    if (a[i][j][k] == 'E')
                        ei = i, ej = j, ek = k;
                }
            }
        }
        queue<zb> q;
        q.push({si, sj, sk, 0});
        bool is = false;
        while (!q.empty())
        {
            if (is == true)
                break;
            int x = q.front().x;
            int y = q.front().y;
            int z = q.front().z;
            int sum = q.front().sum;
            q.pop();
            for (int i = 0; i < 6; i++)
            {
                int tx = x + dx[i];
                int ty = y + dy[i];
                int tz = z + dz[i];
                if (tx < 1 || tx > ceng || ty < 1 || ty > chang || tz < 1 || tz > kuan || a[tx][ty][tz] == '#')
                    continue;
                if (tx == ei && ty == ej && tz == ek)
                {
                    cout << "Escaped in " << sum + 1 << " minute(s)." << endl;
                    is = true;
                    break;
                }
                q.push({tx, ty, tz, sum + 1});
            }
        }
        if (is == false)
            cout << "Trapped!" << endl;
    }
    return 0;
}