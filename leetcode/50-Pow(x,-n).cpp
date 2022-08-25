#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        return pow(x, n);
    }
};

int main()
{
    Solution solu = Solution();
    cout << solu.myPow(2.55, 10) << endl;
    return 0;
}