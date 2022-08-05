#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t found = haystack.find(needle);
        if (found != string::npos)
            return found;
        return -1;
    }
};

int main()
{
    Solution solu = Solution();
    cout << solu.strStr("aaaaa", "baa") << endl;
    return 0;
}