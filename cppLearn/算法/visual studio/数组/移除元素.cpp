//#include <iostream>
//using namespace std;
//
//int test01(int arr[], int  size, int val)
//{
//    int slow = 0;
//    for(int fast = 0; fast < size; fast++)
//    {
//        if(val != arr[fast])
//        {
//            slow++;
//        }
//    }
//    if(slow == 0)
//    {
//        cout << "Ã»ÓĞÕÒµ½!" << endl;
//        return -1;
//    }
//    return slow;
//}
//
//int main()
//{
//    int size = 6;
//    int arr[] = { 4,4,5,6,4,4};
//    int val = 4;
//    int result = test01(arr, size, val);
//    cout << "result:" << result << endl;
//
//    system("pause");
//    return 1;
//}