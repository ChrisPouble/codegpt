#include <iostream>
using namespace std;

class Solution {

public:
    //方法一:PMT数组解
    int KMP(string master_str, string sub_str) {
        //1.next 7
        int  m_len = master_str.size();
        int s_len = sub_str.size();

        int *pmt=new int[s_len];
        pmt[0] = 0;
        int i = 0, j = 1;
        
        for (int idx = 1; idx <s_len;  idx++)
        {
            while (i>=0&&sub_str[j]!=sub_str[pmt[i]])
            {
                i = pmt[i] - 1;
            }

            if (i>=0) {
                pmt[j] = pmt[i] + 1;
               
            }else{
                pmt[j] = 0;
            }
            
            j++;
            i = j - 1;
        }


        //2.match 6
        i = 0;
        j = 0;
        while (i<m_len&&j<s_len) {
            if (master_str[i] == sub_str[j]) {
                i++;
                j++;
            }
            else {
                if (j==0) {
                    i++;
                }
                else {
                    j = pmt[j - 1];
                }
            }
        }

        if (j==s_len) {
            return i - j;
        }

        return -1;
    }

};


//int main() {
//    string master_str = "sdfASDFasdfasfd";
//    string sub_str= "ASDF";
//
//    Solution obj = Solution();
//
//    int result = obj.KMP(master_str,sub_str);
//
//    cout  << endl;
//    cout << result << endl;
//    return 0;
//}