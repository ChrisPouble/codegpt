//#include <iostream>
//using namespace std;
//
//long long f[25][25][25];
//long long w(long long a, long long b, long long c)
//{
//    if (a <= 0 || b <= 0 || c <= 0) return 1;
//    else if (a > 20 || b > 20 || c > 20) return w(20, 20, 20);
//    else if (f[a][b][c] != 0) return f[a][b][c];
//    else if (a < b && b < c) return f[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
//    else return f[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
//}
//
//int main()
//{
//    long long a, b, c;
//    while (1) {
//        cin >> a >> b >> c;
//        if (a == -1 && b == -1 && c == -1) break;
//        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
//    }
//    system("pause");
//    return 0;
//}