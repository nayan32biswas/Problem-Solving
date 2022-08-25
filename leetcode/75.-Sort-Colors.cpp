#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int zero = 0, one = 0;
        for (int num : nums)
        {
            if (num == 0)
                zero++;
            else if (num == 1)
                one++;
        }
        int i = 0, size = nums.size();
        for (; i < size && zero > 0; i++, zero--)
            nums[i] = 0;
        for (; i < size && one > 0; i++, one--)
            nums[i] = 1;
        while (i < size)
            nums[i++] = 2;
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

    vector<int> data = {2, 0, 2, 1, 1, 0};

    solu.sortColors(data);
    output(data);

    return 0;
}