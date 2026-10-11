//#include <iostream>
//using namespace std;
//
//int a[210], b[210], gx[5][5] = { {0, 0, 1, 1, 0}, {1, 0, 0, 1, 0}, {0, 1, 0, 0, 1}, {0, 0, 1, 0, 1}, {1, 1, 0, 0, 0}};
//int main()
//{
//    int n, n1, n2; cin >> n >> n1 >> n2;
//    for (int i = 1; i < n1; i++)
//        cin >> a[i];
//    cin >> a[0];
//    for (int i = 1; i < n2; i++)
//        cin >> b[i];
//    cin >> b[0];
//    int A = 0, B = 0;
//    for (int i = 1; i <= n; i++) {
//        if (a[i % n1] != b[i % n2]) {
//            if (gx[a[i % n1]][b[i % n2]] == 1) A++;
//            else B++;
//        }
//    }
//    cout << A << " " << B;
//    system("pause");
//    return 0;
//}