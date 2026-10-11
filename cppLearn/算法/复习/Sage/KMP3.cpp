#include <iostream>
using namespace std;

class Solution {

public:
    //方法三:终极版Next,匹配法
    int KMP(string master_str, string sub_str) {
        //1.next 7
        int  m_len = master_str.size();
        int s_len = sub_str.size();

        int* next = new int[s_len];
        next[0] = -1;
        cout << next[0] << endl;
        int i = 0, j = -1;
        while (i<s_len) {
            if (j==-1||sub_str[i]==sub_str[j]) {
                i++;
                j++;
                next[i] = j;
                cout<< i<<"  " << next[i] << endl;
            }
            else {   
                j = next[j];
            }
        }

        //2.match 6
        i = 0;
        j = 0;
        while (i < m_len && j < s_len) {
            if (j == -1 || master_str[i] == sub_str[j]) {
                i++;
                j++;
            }
            else {
                j = next[j];
            }
        }

        if (j == s_len) {
            return i - j;
        }

        return -1;
    }

};



//int main() {
//    string master_str = "sdabacababasdfasfd";
//    string sub_str = "abacabab";
//
//    Solution obj = Solution();
//
//    int result = obj.KMP(master_str, sub_str);
//
//    cout << endl;
//    cout << result << endl;
//    return 0;
//}