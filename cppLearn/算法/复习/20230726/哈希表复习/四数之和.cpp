#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    for (int k = 0; k < nums.size(); k++)
    {
        if (k > 0 && nums[k] == nums[k - 1])
        {
            continue;
        }
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > 0) return result;

            if (i > 1 && nums[i] == nums[i - 1])
            {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while (right > left)
            {
                if (nums[k] + nums[i] > target - nums[left] - nums[right])
                {
                    right--;
                }
                else if (nums[k] + nums[i] < target - nums[left] - nums[right])
                    {
                        left++;
                    }
                else
                {
                    result.push_back(vector<int> {nums[k], nums[i], nums[left],
                        nums[right]});

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
    }
    return result;
}

//int main()
//{
//    int target = 3;
//
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
//    vector<vector<int>> ret = fourSum(num1, target);
//    system("pause");
//    return 0;
//}