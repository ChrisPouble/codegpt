#include <iostream>
#include <vector> 
#include <algorithm>
#include <unordered_map>
using namespace std;

void swal(string s, int start, int end)
{
    for (int i = start, j = end; i < j; i++, j--)
    {
        swap(s[i], s[j]);
    }
}

//删除多余空格
void removeExtraSpace(string& s)
{
    int slowIndex = 0, fastIndex = 0; //定义快指针,慢指针
                                      
    //去掉字符串前面的空格
    while (s.size() > 0 && fastIndex < s.size() && s[fastIndex] == ' ')
    {
        fastIndex++;
    }

    //去掉字符串中间多余的空格
    for (; fastIndex < s.size(); fastIndex++)
    {
        if(fastIndex - 1 > 0 
            && s[fastIndex] == s[fastIndex - 1] 
            && s[fastIndex] == ' ')
        {
            continue;
        }
        else
        {
            s[slowIndex++] = s[fastIndex];
        }
    }

    //去掉字符串尾部的空格
    for (int i = s.size(); s[i] == ' '; i--) 
    {
        if (slowIndex - 1 > 0)
        {
            s.resize(slowIndex - 1);
        }
    }
    s.resize(slowIndex);
}

class Person
{
public:
     string reverweWords(string s)
     {
         removeExtraSpace(s); //去掉多余空格
         swal(s, 0, s.size() - 1); //将字符串全部反转
         int start = 0; //反转的单词在字符串中的起始位置
         int end = s.size() - 1; // 反转的单词在字符串中的终止位置
         bool entry = false;

         for (int i = 0; i < s.size(); i++) //开始反转单词
         {
             if ((!entry) || (s[i] != ' ' && s[i - 1] == ' '))
             {
                 start = i; //确定单词起始位置
                 entry = true; //进入单词区间
             }

             //单词后有空格的情况, 空格就是分词符
             if (entry && s[i] == ' ' && s[i - 1] != ' ')
             {
                 end = i - 1; //确定单词终止位置
                 entry = false; //确定单词区间
                 swal(s, start, end);
             }

             //最后一个结尾单词之后没有空格的情况
             if (entry && (i == (s.size() - 1)) && s[i] != ' ')
             {
                 end = i; //确定单词终止位置
                 entry = false; //确定单词区间
                 swal(s, start, end);
             }
         }
         return s;
     }
};

void test01()
{
    Person p;
    string s = " hello wolrd! ";
    string b = p.reverweWords(s);
    cout << "b = " << b << endl;
}

int main()
{
    test01();
    system("pause");
    return 0;
}