#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {

        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0, num, median = 0, total = m + n, prev;
        int mid = total / 2;
        double ans = 0;
        while (true)
        {
            if (i < m && j < n)
            {
                if (nums1[i] < nums2[j])
                {
                    num = nums1[i++];
                }
                else
                {
                    num = nums2[j++];
                }
            }
            else if (i >= m && j >= n)
                break;
            else
            {
                if (i < m)
                    num = nums1[i++];
                else if (j < n)
                    num = nums2[j++];
            }
            if (i + j > mid)
            {
                if (total % 2 == 1)
                {
                    ans = num;
                    break;
                }
                else
                {
                    ans = double(num + prev) / 2;
                    break;
                }
            }
            prev = num;
        }
        return ans;
    }
};

int main()
{
    Solution solu = Solution();

    // int arr1[] = {1, 3};
    // int arr2[] = {2};

    int arr1[] = {1, 4, 7};
    int arr2[] = {3};
    vector<int> one(arr1, arr1 + sizeof(arr1) / sizeof(arr1[0]));
    vector<int> two(arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]));
    cout << solu.findMedianSortedArrays(one, two) << endl;
    return 0;
}