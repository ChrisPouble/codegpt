#include <iostream>
using namespace std;

bool isAnagram(string s1, string s2)
{
    int hash[26] = {0};
    for (int i = 0; i < s1.size(); i++)
    {
        hash[s1[i] - 'a']++;
    }

    for (int i = 0; i < s2.size(); i++)
    {
        hash[s2[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (hash[i] != 0)
        {
            return false;
        }
    }
    return true;
}

//int main()
//{
//    string s1 = "abbc";
//    string s2 = "bbacf";
//    bool ret = isAnagram(s1,s2);
//
//    if (ret)
//    {
//        cout << "ret = true" << endl;
//    }
//    else
//    {
//        cout << "ret = false" << endl;
//    }
//    system("pause");
//    return 0;
//}