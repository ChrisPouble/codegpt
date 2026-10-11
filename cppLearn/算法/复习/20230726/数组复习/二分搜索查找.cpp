#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;
    int middle = arr.size() / 2;
    while (left <= right)
    {
        if (arr[middle] > target)
        {
            right = middle - 1;
        }
        else if (arr[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            return middle;
        }
    }
    return -1;
}

//int main()
//{
//    vector<int> arr;
//    arr.push_back(1);
//    arr.push_back(2);
//    arr.push_back(5);
//    arr.push_back(7);
//    arr.push_back(10);
//    arr.push_back(15);
//    arr.push_back(19);
//    arr.push_back(23);
//    arr.push_back(27);
//    int target = 10;
//    int ret = binarySearch(arr, target);
//
//    cout << "ret = " << ret << endl;
//    
//    system("pause");
//    return 0;
//}