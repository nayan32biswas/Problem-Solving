// Unsolved
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    string addition(string &value1, string &value2)
    {
        string x;
        int len, top_len, sum = 0;
        top_len = value1.size();
        len = value2.size();
        if (top_len < len)
        {
            swap(value1, value2);
            swap(len, top_len);
        }
        for (int i = top_len - 1, k = len - 1; i >= 0; i--, k--)
        {
            if (k < 0)
                sum += (value1[i] - 48);
            else
                sum += ((value1[i] - 48) + (value2[k] - 48));
            x += (sum % 10) + 48;
            sum /= 10;
        }
        if (sum > 0)
            x += (sum + 48);
        reverse(x.begin(), x.end());
        return x;
    }
    string multiply(string value1, string value2)
    {
        string temp = "";
        vector<string> sum;
        reverse(value1.begin(), value1.end());
        reverse(value2.begin(), value2.end());
        while (value1.back() == '0')
            value1.pop_back();
        while (value2.back() == '0')
            value2.pop_back();
        if (value1.size() == 0 || value2.size() == 0)
            return "0";
        int space = 0;
        for (auto val1 : value1)
        {
            sum.push_back(temp);
            int mult = space;
            while (mult--)
                sum.back() += "0";
            val1 -= '0';
            mult = 0;
            for (auto it : value2)
            {
                it -= '0';
                mult += (val1 * it);
                sum.back() += ((mult % 10) + '0');
                mult /= 10;
            }
            if (mult > 0)
            {
                sum.back() += ((mult % 10) + '0');
            }
            reverse(sum.back().begin(), sum.back().end());
            space++;
        }
        string ans = "";
        for (auto it : sum)
            ans = addition(it, ans);
        return ans;
    }
};

int main()
{
    Solution solu = Solution();

    cout << solu.multiply("123", "342") << endl;
    return 0;
}