#include <bits/stdc++.h>
#define maxn 500010
using namespace std;

//归并排序
long long ans;
int len, arr[maxn], temp[maxn]; //辅助空间 
void MergeSort(int arr[], int start, int end) { //start和end分别是左边界和右边界
	if (start >= end) return;
	int mid = (start + end) / 2, i = start, j = mid + 1;
	MergeSort(arr, start, mid); //分成两个子序列 
	MergeSort(arr, mid + 1, end);
 
	// 合并两个有序序列
	int k = 1; // 表示辅助空间有多少个元素
	while (i <= mid && j <= end) {
		if (arr[i] < arr[j]) temp[k++] = arr[i++]; //没有产生逆序对
		else ans += mid - i + 1, temp[k++] = arr[j++]; //如果产生了逆序对，则答案加上左边剩余元素个数
	}
	while (i <= mid) temp[k++] = arr[i++]; //把剩下数的合并
	while (j <= end) temp[k++] = arr[j++]; //同上 
	// 把辅助空间的数据放到原空间
	for (int i = start; i <= end; i++)
		arr[i] = temp[i - start + 1];
}


int main() {
	cin >> len;
	for (int i = 1; i <= len; i++)
		cin >> arr[i];
	MergeSort(arr, 1, len);
	cout << ans << endl;
	return 0;
}
