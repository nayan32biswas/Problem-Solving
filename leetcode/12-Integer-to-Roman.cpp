#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string getNum(int num, string ch)
    {
        string ans = "";
        while (num--)
        {
            ans += ch;
        }
        return ans;
    }
    string intToRoman(int num)
    {
        int numState[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string valueState[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string ans = "";
        int length = sizeof(numState) / sizeof(numState[0]);

        for (int i = 0; i < length && num; i++)
        {
            if (num >= numState[i])
            {
                ans += getNum(num / numState[i], valueState[i]);
                num = num % numState[i];
            }
        }
        return ans;
    }
};

int main()
{
    Solution solu = Solution();
    cout << solu.intToRoman(1994) << endl;
    return 0;
}