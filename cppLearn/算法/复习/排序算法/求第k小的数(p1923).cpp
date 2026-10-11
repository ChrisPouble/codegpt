#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n4, k4;
vector<int> vec2;
void p1923(int left, int right)
{
    if (left == right) {
        cout << vec2[left] << endl;
        exit(0);
    }
    int i, j, pivot;
    i = left, j = right, pivot = vec2[(left + right) / 2];//这次选中间元素

    do {
        while (vec2[i] < pivot) i++;
        while (vec2[j] > pivot) j--;
        if (i <= j) {
            swap(vec2[i], vec2[j]);
            i++, j--;
        }
    } while (i <= j);
    //for (int i = left; i <= right; i++) cout << vec2[i] << " ";
    //cout << endl;
    if (k4 <= j) p1923(left, j);
    else if (i <= k4) p1923(i, right);
    else p1923(j + 1, i - 1);
}

//int main()
//{
//    std::ios::sync_with_stdio(false);//输入时间变快
//    cin >> n4 >> k4;
//    for (int i = 0; i < n4; i++)
//    {
//        int t;
//        cin >> t;
//        vec2.push_back(t);
//    }
//
//    p1923(0, vec2.size() - 1);
//    system("pause");
//    return 0;
//}