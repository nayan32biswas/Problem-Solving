// Unsolved
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

class Solution
{
public:
    string getStr(int a, int b, int c, int d)
    {
        string ans = "";
        ostringstream str1;
        str1 << a, ans += str1.str();
        str1 << b, ans += str1.str();
        str1 << c, ans += str1.str();
        str1 << d, ans += str1.str();

        return ans;
    }
    int binary_search_lower(vector<int> &nums, int key, int lo, int hi)
    {
        int mid = 0, start = lo, End = hi - 1;
        while (End - start > 1)
        {
            mid = (start + End) / 2;
            if (nums[mid] < key)
                start = mid;
            else
                End = mid;
        }
        if (nums[End] <= key)
            return End;
        return start;
    }
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int length = nums.size(), pos;
        long long int diff;
        map<string, bool> status;
        for (int i = 0; i < length; i++)
        {
            long long int num1 = nums[i];
            for (int j = i + 1; j < length; j++)
            {
                for (int k = j + 1; k < length; k++)
                {
                    diff = target - (num1 + nums[j] + nums[k]);
                    pos = binary_search_lower(nums, diff, k + 1, length);
                    if (pos < length && nums[pos] == diff && pos>k)
                    {
                        string temp = getStr(nums[i], nums[j], nums[k], nums[pos]);
                        if (status[temp] != true)
                        {
                            status[temp] = true;
                            vector<int> temp = {nums[i], nums[j], nums[k], nums[pos]};
                            ans.push_back(temp);
                        }
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution = Solution();

    int arr[] = {1, 0, -1, 0, -2, 2};
    vector<int> one(arr, arr + sizeof(arr) / sizeof(arr[0]));
    vector<vector<int>> ans = solution.fourSum(one, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            printf("%d ", ans[i][j]);
        }
        puts("");
    }
    return 0;
}