#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<int>> threesum(vector<int>& nums)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0) return result;

        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int left = i + 1;
        int right = nums.size() - 1;

        while (right > left)
        {
            if (nums[i] + nums[left] + nums[right] > 0)
            {
                right--;
            }
            else if (nums[i] + nums[left] + nums[right] < 0)
            {
                left++;
            }
            else
            {
                result.push_back(vector<int> {nums[i], nums[left], nums[right]});


                while (right > left && nums[right] == nums[right - 1])
                {
                    right--;
                }

                while (right > left && nums[left] == nums[left + 1])
                {
                    left++;
                }

                right++;
                left--;
            }
        }
    }
    return result;
}

//int main()
//{
//    vector<int>num1;
//    num1.push_back(-1);
//    num1.push_back(3);
//    num1.push_back(4);
//    num1.push_back(-3);
//    num1.push_back(0);
//    num1.push_back(1);
//    num1.push_back(3);
//    num1.push_back(-3);
//
//    vector<vector<int>> ret = threesum(num1);
//    system("pause");
//    return 0;
//}