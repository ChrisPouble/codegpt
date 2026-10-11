//#include <iostream>
//using namespace std;
//
//int n, maxt, mint, maxi, mini, a[1000];
//void one() {
//    for (int i = 0, j = n - 1; i < j; i++, j--) {
//        maxt = mint = a[i];
//        maxi = mini = i;
//        for (int r = i + 1; r < j; r += 2) {
//            if (a[r] > a[r + 1]) {
//                if (maxt < a[r]) maxt = a[r], maxi = r;
//                if (mint > a[r + 1]) mint = a[r + 1], mini = r + 1;
//            } else {
//                if (maxt < a[r + 1]) maxt = a[r + 1], maxi = r + 1;
//                if (mint > a[r]) mint = a[r], mini = r;
//            }
//        }
//        swap(a[j], a[maxi]);
//        if (mini == j) mini = maxi;
//        swap(a[i], a[mini]);
//    }
//}
//
//void two() {
//    for (int i = 0, j = n - 1; i <= j; i++, j--) {
//        maxt = a[i] > a[i + 1] ? a[i] : a[i + 1];
//        mint = a[i] > a[i + 1] ? a[i + 1] : a[i];
//        maxi = a[i] > a[i + 1] ? i : i + 1;
//        mini = a[i] > a[i + 1] ? i + 1 : i;
//        for (int r = i + 2; r < j; r += 2) {
//            if (a[r] > a[r + 1]) {
//                if (maxt < a[r]) maxt = a[r], maxi = r;
//                if (mint > a[r + 1]) mint = a[r + 1], mini = r + 1;
//            } else {
//                if (maxt < a[r + 1]) maxt = a[r + 1], maxi = r + 1;
//                if (mint > a[r]) mint = a[r], mini = r;
//            }
//        }
//        swap(a[j], a[maxi]);
//        if (mini == j) mini = maxi;
//        swap(a[i], a[mini]);
//    }
//    if (a[n / 2] < a[n / 2 - 1]) swap(a[n / 2], a[n / 2 - 1]);
//}
//
//int main() {
//    cin >> n;
//    for (int i = 0; i < n; i++)
//        cin >> a[i];
//
//    if (n % 2) one();
//    else two();
//
//    for (int i = 0; i < n; i++)
//        cout << a[i] << " ";
//
//    cout << endl;
//    system("pause");
//    return 0;
//}