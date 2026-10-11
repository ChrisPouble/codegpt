#include <iostream>
#include <vector>
using namespace std;

void reverse(string& s, int start, int end)
{
    for (int i = start, j = end; i < j; i++, j--)
    {
        swap(s[i], s[j]);
    }
}

void removeExtraSpace(string& s)
{
    int slow = 0, fast = 0;

    //É¾³ý×Ö·û´®Ç°ÃæµÄ¿Õ¸ñ
    while (s.size() > 0 && fast < s.size() && s[fast] == ' ')
    {
        fast++;
    }

    //É¾³ý×Ö·û´®ÖÐ¼ä¶àÓàµÄ¿Õ¸ñ
    for (; fast < s.size(); fast++)
    {
        if (fast - 1 > 0 && s[fast - 1] == s[fast] && s[fast] == ' ')
        {
            continue;
        }
        else
        {
            s[slow++] = s[fast];
        }
    }

    //É¾³ý×Ö·û´®Î²²¿µÄ¿Õ¸ñ
    if (slow - 1 > 0 && s[slow - 1] == ' ')
    {
        s.resize(slow - 1);
    }
    else
    {
        s.resize(slow);
    }
}

string reverseWords(string s)
{
    removeExtraSpace(s);
    reverse(s, 0, s.size() - 1);

    int start = 0;
    int end = 0;
    bool entry = false;

    for (int i = 0; i < s.size(); i++)
    {
        if ((!entry) || (s[i] != ' ' && s[i - 1] == ' '))
        {
            start = i;
            entry = true;
        }

        if (entry && s[i] == ' ' && s[i - 1] != ' ')
        {
            end = i - 1;
            entry = false;
            reverse(s, start, end);
        }

        if (entry && (i == (s.size() - 1)) && s[i] != ' ')
        {
            end = i;
            entry = false;
            reverse(s, start, end);
        }
    }
    return s;
}

//int main()
//{
//    string s = " hello  world! ";
//
//    string ret = reverseWords(s);
//    cout << "ret = " << ret << endl;
//    system("pause");
//    return 0;
//}