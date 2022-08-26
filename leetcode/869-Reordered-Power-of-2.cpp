#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMatch(int x, unsigned input[])
    {
        int temp[10];
        memset(temp, 0, sizeof(temp));

        while (x > 0)
        {
            temp[x % 10]++;
            x = x / 10;
        }
        for (int i = 0; i < 10; i++)
        {
            if (input[i] != temp[i])
                return false;
        }
        return true;
    }
    bool reorderedPowerOf2(int n)
    {

        unsigned x = n, input[10], digit = 0;
        memset(input, 0, sizeof(input));

        while (x > 0)
        {
            digit++;
            input[x % 10]++;
            x = x / 10;
        }

        long long low = pow(10, digit - 1), hi = pow(10, digit);

        x = 1;
        while (x <= hi && x < 1000000000)
        {
            if (x >= low)
            {
                if (isMatch(x, input))
                    return true;
            }
            x = x * 2;
        }
        return false;
    }
};
int main()
{
    Solution solu = Solution();

    cout << solu.reorderedPowerOf2(503687912) << endl;

    return 0;
}
