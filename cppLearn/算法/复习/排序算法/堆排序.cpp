#include <iostream>
#include <vector>
using namespace std;

int heap[200005], n, len;
void up(int x) {
    heap[++len] = x;
    int temp = len;
    while (temp > 1 && heap[temp] < heap[temp / 2]) {
        swap(heap[temp], heap[temp / 2]);
        temp /= 2;
    }
}

void down() {
    heap[1] = heap[len--];
    int temp = 1;
    while (temp <= len / 2) {
        if (temp * 2 + 1 <= len && heap[temp * 2] < heap[temp * 2 + 1]) temp = temp * 2;
        else if (temp * 2 + 1 <= len && heap[temp * 2] >= heap[temp * 2 + 1]) temp = temp * 2 + 1;
        else if (temp * 2 + 1 > len && temp * 2 <= len) temp = temp * 2;
        else break;
        if (heap[temp / 2] < heap[temp]) break;
        else swap(heap[temp / 2], heap[temp]);
    }
}

//int main() {
//    cin >> n;
//    for (int i = 1; i <= n; i++) {
//        cin >> heap[i];
//        up(heap[i]);
//    }
//    for (int i = 1; i <= n; i++) {
//        cout << heap[1] << " ";
//        down();
//    }
//    return 0;
//}