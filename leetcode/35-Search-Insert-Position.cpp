#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int length = nums.size();
        if(target>nums[length-1]){
            return length;
        }
        if(target<=nums[0]){
            return 0;
        }
        return int(lower_bound(nums.begin(), nums.end(), target)-nums.begin());
    }
};

int main()
{
    Solution solu = Solution();

    int arr[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    vector<int> one(arr, arr + sizeof(arr) / sizeof(arr[0]));
    cout << solu.searchInsert(one, 10) << endl;
    return 0;
}