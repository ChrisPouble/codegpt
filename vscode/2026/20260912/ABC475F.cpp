#include <bits/stdc++.h>
using namespace std;

int H, W;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> H >> W;

    vector <string> S(H + 1);
    for (int i = 0; i < H; i++)
        cin >> S[i];

    bool trans = 0;
    int newH, newW;

    if (W > H) {
        trans = true;
        newH = W, newW = H;
    } else {
        newH = H, newW = W;
    }

    vector<vector<int> > cols(newW + 1);

    if (!trans) {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (S[i][j] != '.') continue;
                cols[j + 1].push_back(i + 1);
            }
        }
    } else {
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (S[i][j] != '.') continue;
                cols[i + 1].push_back(j + 1);
            }
        }
    }

    vector <char> inS(newH + 1, 0), inA(newH + 1, 0), inB(newH + 1, 0);
    vector <int> sup; vector <char> Aflag, Bflag;
    long long ans = 1;

    for (int c1 = 1; c1 <= newW; c1++) {
        for (int row : cols[c1])
            inA[row] = 1;
        sup.clear();

        for (int c2 = c1; c2 <= newW; c2++) {
            for (int row : cols[c2]) {
                if (!inS[row]) {
                    inS[row] = 1;
                    sup.push_back(row);
                }
            }

            for (int row : cols[c2])
                inB[row] = 1;

            Aflag.clear(); Bflag.clear();
            for (int i = 1; i <= newH; i++) {
                if (!inS[i]) continue;
                Aflag.push_back(inA[i]);
                Bflag.push_back(inB[i]);
            }

            int k = (int)Aflag.size();
            if (k > 0) {
                int nxtA = k, nxtB = k;
                for (int idx = k - 1; idx >= 0; idx--) {
                    if (Aflag[idx]) nxtA = idx;
                    if (Bflag[idx]) nxtB = idx;
                    int j = max(idx, max(nxtA, nxtB));
                    if (j < k) ans += (k - j);
                }
            }

            for (int row : cols[c2])
                inB[row] = 0;
        }

        for (int row : cols[c1])
            inA[row] = 0;
        
        for (int row : sup)
            inS[row] = 0;
    }

    cout << ans << "\n";
    return 0;
}