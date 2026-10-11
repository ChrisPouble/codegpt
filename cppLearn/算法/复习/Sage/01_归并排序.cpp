#include <iostream>
using namespace std;

void heBing(int A[], int low, int mid, int high)
{
    int* B = new int[high - low + 1];
    int i = low, j = mid + 1, k = 0;

    while (i <= mid && j <= high)
    {
        if (A[i] <= A[j])
        {
            B[k++] = A[j++];
        }
        else
        {
            B[k++] = A[i++];
        }
    }

    while (i <= mid) B[k++] = A[i++];
    while (j <= high) B[k++] = A[j++];

    for (i = low, k = 0; i <= high; i++)
    {
        A[i] = B[k++];
    }
    delete[]B;
}

void heBingSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        heBingSort(A, low, mid);
        heBingSort(A, mid + 1, high);
        heBing(A, low, mid, high);
    }
}

//int main()
//{
//    int A[7] = {2, 5, 7, 4, 11, 9, 6};
//    heBingSort(A, 0, sizeof(A) / sizeof(int) - 1);
//    for (int i = 0; i < 7; i++)
//    {
//        cout << A[i] << " ";
//    }
//    cout << endl;
//    system("pause");
//    return 0;
//}