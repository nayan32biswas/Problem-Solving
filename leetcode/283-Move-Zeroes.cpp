#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int pos = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[pos] == 0)
            {
                if (nums[i] != 0)
                {
                    nums[pos] = nums[i];
                    nums[i] = 0;
                    pos++;
                }
            }
            else
            {
                pos++;
            }
        }
    }
};

void output(vector<int> &matrix)
{
    for (auto it : matrix)
        cout << it << " ";
    puts("");
}
int main()
{
    Solution solu = Solution();

    vector<int> data = { -1,0, -2, -3, 0};

    solu.moveZeroes(data);
    output(data);

    return 0;
}