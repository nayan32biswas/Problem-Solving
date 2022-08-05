// Unsolved
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int getArea(int lo, int hi, vector<int> &height)
    {
        return (hi - lo) * min(height[lo], height[hi]);
    }
    int maxSum(vector<int> &height)
    {
        int ans = 0, area = 0, length = height.size(), newArea = 0;
        int lo = 0, hi = 0, incH = 0, incL = 0;
        for (; lo < length && hi <= length;)
        {
            if (hi == length)
            {
                newArea = getArea(lo, hi - 1, height);
                area = newArea;
                ans = max(ans, area);
                // printf("start -> %d %d\n", lo, hi);
                lo++;
                continue;
            }
            incL = getArea(lo + 1, hi, height);
            incH = getArea(lo, hi + 1, height);

            if (incL <= incH)
            {
                hi++;
            }
            else
            {
                lo++;
            }

            ans = max(ans, getArea(lo, hi, height));
            // printf("last -> %d %d, (%d %d) -> %d\n", lo, hi, incL, incH, ans);
        }
        return ans;
    }
    int maxArea(vector<int> &height)
    {
        int first = maxSum(height);
        reverse(height.begin(), height.end());
        int second = maxSum(height);
        return max(first, second);
    }
};

int main()
{
    Solution solu = Solution();

    int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    // int arr[] = {1, 2, 3, 3, 1, 2, 1, 1, 1, 1, 7, 8, 1, 1, 1, 1};
    vector<int> one(arr, arr + sizeof(arr) / sizeof(arr[0]));
    cout << solu.maxArea(one) << endl;
    return 0;
}