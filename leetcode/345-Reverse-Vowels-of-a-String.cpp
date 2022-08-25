#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        bool vowels[128];
        memset(vowels, false, sizeof(vowels));
        vowels['A'] = true, vowels['E'] = true, vowels['I'] = true, vowels['O'] = true, vowels['U'] = true;
        vowels['a'] = true, vowels['e'] = true, vowels['i'] = true, vowels['o'] = true, vowels['u'] = true;

        for (int i = 0, j = s.size(); i < j;)
        {
            if (!vowels[s[i]])
                i++;
            if (!vowels[s[j]])
                j--;
            if (vowels[s[i]] && vowels[s[j]])
            {
                swap(s[i], s[j]);
                i++, j--;
            }
        }
        return s;
    }
};

int main()
{
    Solution solu = Solution();

    cout << solu.reverseVowels("aA") << endl;

    return 0;
}