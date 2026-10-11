#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;
vector<int> KuaiSuSort(int left, int right)
{
    //版本一
    //if (left >= right) return {};
    //int i, j, pivot;
    //i = left, j = right, pivot = vec[left];
    //while (i < j)
    //{
    //    while (vec[j] >= pivot && i < j) j--;
    //    while (vec[i] <= pivot && i < j) i++;

    //    if (i < j)
    //    {
    //        swap(vec[i], vec[j]);
    //    }
    //}
    //swap(vec[i], vec[left]);

    //KuaiSuSort(left, i - 1);
    //KuaiSuSort(i + 1, right);
    //return vec;
    
    //版本二
    if (left >= right) return {};
    int i = left, j = right, pivot = vec[(left + right) / 2];
    do { //此处要用do while, 用while会错
        while (vec[i] < pivot) i++;
        while (vec[j] > pivot) j--;
        if (i <= j) { //交换前要先判断
            swap(vec[i], vec[j]);
            i++, j--;
        }
    } while (i <= j);
    if(left < j) KuaiSuSort(left, j); //看看left是否小于j
    if(right > i) KuaiSuSort(i, right); //看看right是否大于i
    return vec;
}

//int main()
//{
//    int n;
//    cin >> n;
//    for (int i = 0; i < n; i++)
//    {
//        int t;
//        cin >> t;
//        vec.push_back(t);
//    }
//    vector<int> ret = KuaiSuSort(0, vec.size() - 1);
//    for (int i = 0; i < ret.size(); i++)
//    {
//        cout << ret[i] << " ";
//    }
//    cout << endl;
//    system("pause");
//    return 0;
//}