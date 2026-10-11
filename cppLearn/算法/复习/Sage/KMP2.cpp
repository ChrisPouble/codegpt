/*       int m = master_str.size();
            int s = sub_str.size();
            int* next = new int[s];
            next[0] = 0;
            int i = 0, j = 1;

            for (int idx = 1; idx < s; idx++)
            {
                while (i >= 0 && sub_str[j] != sub_str[next[i]])
                {
                    i = next[i] - 1;
                }

                if (i >= 0)
                {
                    next[j] = next[i] + 1;
                }
                else
                {
                    next[j] = 0;
                }

                j++;
                i = j - 1;
            }

            i = 0, j = 0;
            while (i < m && j < s)
            {
                if (j == -1 || master_str[i] == sub_str[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    j = next[j];
                }
            }

            if (j == s - 1)
            {
                return i - j;
            }
            return -1;
        }
    };
*/#include <iostream>
using namespace std;

class Solution {

public:
    //方法二:PMT->Next数组解
    int KMP(string master_str, string sub_str) {
        //1.next 7
        int m = master_str.size();
        int s = sub_str.size();
        int* next = new int[s];
        next[0] = 0;
        int i = 0, j = 1;

        for (int idx = 0; idx < s; idx++)
        {
            while (i >= 0 && sub_str[j] != sub_str[next[i]])
            {
                i = next[i] - 1;
            }

            if (i >= 0)
            {
                next[j] = next[i] + 1;
            }
            else
            {
                next[j] = 0;
            }
            j++;
            i = j - 1;
        }

        i = 0, j = 0;
        while (i < m && j < s)
        {
            if (j == -1 || master_str[i] == sub_str[j])
            {
                i++;
                j++;
            }
            else
            {
                j = next[j];
            }
        }

        if (j == s - 1)
        {
            return i - j;
        }
        return -1;
    }
};



int main() {
    string master_str = "sdaaaafASDFasdfasfd";
    string sub_str = "ASDF";

    Solution obj = Solution();

    int result = obj.KMP(master_str, sub_str);
    cout << result << endl;
    return 0;
}