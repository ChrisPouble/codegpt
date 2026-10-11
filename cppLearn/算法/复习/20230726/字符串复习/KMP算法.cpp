#include <iostream>
using namespace std;

int* Next(char* duan)
{
    int* next = (int*)calloc(strlen(duan), sizeof(int));

    next[0] = -1;
    int c = 0, d = -1;

    while (c < (int)strlen(duan) - 1)
    {
        if (d == -1 || duan[c] == duan[d])
        {
            c++;
            d++;
            next[c] = d;
        }
        else
        {
            d = next[d];
        }
    }
    return next;
}

int IndexKmp(char* chang, char* duan)
{
    int* next = Next(duan);
    int c = 0, d = 0;

    while ((c < strlen(chang) && d < (int)strlen(duan)))
    {
        if (d == -1 || chang[c] == duan[d])
        {
            c++;
            d++;
        }
        else
        {
            d = next[d];
        }
    }
    delete next;
    return d == strlen(duan) ? c - d : -1;
}

int main()
{
    char c[3] = { 'a', 'b', 'c' };
    char d[8] = { 'a', 'c', 'a', 'b', 'a', 'a', 'b', 'c' };

    int ret = IndexKmp(d, c);
    cout << "ret = " << ret << endl;
    return 0;
}