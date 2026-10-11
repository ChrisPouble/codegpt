//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//vector<int> func(vector<int>& arr)
//{
//    int k = arr.size() - 1;
//    int temp;
//    for (int i = 0, j = arr.size() - 1; i <= j; )
//    {
//        if (arr[i] * arr[i] >= arr[j] * arr[j])
//        {
//            arr[k] = arr[i] * arr[i];
//            k--;
//            i++;
//        }
//        else
//        {
//            arr[k] = arr[j] * arr[j];
//            k--;
//            j--;
//        }
//    }
//    return arr;
//}
//
//vector<int> func1(vector<int>& arr)
//{
//    for (int i = 0; i < arr.size(); i++)
//    {
//        arr[i] = arr[i] * arr[i];
//    }
//
//    sort(arr.begin(), arr.end());
//
//    return arr;
//}
//
//void test01()
//{
//    vector<int> arr;
//    arr.push_back(-5);
//    arr.push_back(1);
//    arr.push_back(2);
//    arr.push_back(3);
//    vector<int> ret = func1(arr);
//
//    for (int i = 0; i < arr.size(); i++)
//    {
//        cout << ret[i] << " ";
//    }
//    cout << endl;
//}
//
////int main()
////{
////    test01();
////    system("pause");
////    return 0;
////}