#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        int state[128];
        memset(state, 0, sizeof(state));
        for (auto ch : magazine)
            state[ch]++;
        for (auto ch : ransomNote)
        {
            if (--state[ch] < 0)
                return false;
        }
        return true;
    }
};
int main()
{
    Solution solu = Solution();

    cout << solu.canConstruct("a", "b") << endl;
    return 0;
}