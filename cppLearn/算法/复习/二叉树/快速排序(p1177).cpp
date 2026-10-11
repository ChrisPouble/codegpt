//#include <iostream>
//using namespace std;
//
//int vec[100];
//int* KuaiSuSort(int left, int right) {
//    if (left >= right) return {};
//    int i = left, j = right, pivot = vec[left];
//    
//    while (i < j) {
//        while (vec[j] >= pivot && i < j) j--;
//        while (vec[i] <= pivot && i < j) i++;
//        if (i < j) swap(vec[i], vec[j]);
//    }
//
//    swap(vec[i], vec[left]);
//    KuaiSuSort(left, i - 1);
//    KuaiSuSort(i + 1, right);
//    return vec;
//}
//
//int main() {
//    int n; cin >> n;
//    for (int i = 0; i < n; i++)
//        cin >> vec[i];
//    
//    KuaiSuSort(0, n - 1);
//    for (int i = 0; i < n; i++)
//        cout << vec[i] << " ";
//    system("pause");
//    return 0;
//}