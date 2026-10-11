//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int n, a[20] = { 1, 1 }; //a[i]表示i个元素的出管方式有多少，其中a[0] = a[1] = 1;
//    cin >> n;
//    for (int i = 2; i <= n; i++) //从2枚举到n, 枚举a[i]
//        for (int j = 0; j <= i - 1; j++) //从0枚举到i - 1, 枚举j
//            a[i] += a[j] * a[i - j - 1]; //a[i] = （比j先入管且先出管的数）*（比j后入管且先出管的数）
//    cout << a[n] << endl;
//    system("pause");
//    return 0;
//}