#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfThree(long long n)
    {
        for (long long i = 0; i < 30; i++)
        {
            if (pow(3, i) == n)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution solu = Solution();
    cout << solu.isPowerOfThree(34867844010) << endl;
    return 0;
}