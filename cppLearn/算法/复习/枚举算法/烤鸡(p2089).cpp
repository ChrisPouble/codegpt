#include <iostream>
using namespace std;

void p2089()
{
    int n, ans = 0;
    cin >> n;
    if (n < 10 || n > 30)
    {
        cout << 0 << endl;
        return;
    }
    for (int a = 1; a <= 3; a++)
    {
        for (int b = 1; b <= 3; b++)
        {
            for (int c = 1; c <= 3; c++)
            {
                for (int d = 1; d <= 3; d++)
                {
                    for (int e = 1; e <= 3; e++)
                    {
                        for (int f = 1; f <= 3; f++)
                        {
                            for (int g = 1; g <= 3; g++)
                            {
                                for (int h = 1; h <= 3; h++)
                                {
                                    for (int i = 1; i <= 3; i++)
                                    {
                                        for (int j = 1; j <= 3; j++)
                                        {
                                            if (a + b + c + d + e + f + g + h + i + j == n)
                                                ans++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;

    for (int a = 1; a <= 3; a++)
    {
        for (int b = 1; b <= 3; b++)
        {
            for (int c = 1; c <= 3; c++)
            {
                for (int d = 1; d <= 3; d++)
                {
                    for (int e = 1; e <= 3; e++)
                    {
                        for (int f = 1; f <= 3; f++)
                        {
                            for (int g = 1; g <= 3; g++)
                            {
                                for (int h = 1; h <= 3; h++)
                                {
                                    for (int i = 1; i <= 3; i++)
                                    {
                                        for (int j = 1; j <= 3; j++)
                                        {
                                            if (a + b + c + d + e + f + g + h + i + j == n)
                                                cout << a << " " << b << " " << c << " " << 
                                                d << " " << e << " " << f << " " << g << " " << 
                                                h << " " << i << " " << j << endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

//int main()
//{
//    p2089();
//    return 0;
//}