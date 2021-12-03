#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int len = str.size();
    string ans = "";
    if (len % 2 == 0)
    {
        for (int i = 0, j = len - 1; i < j; i++, j--)
        {
            ans += str[j];
            ans += str[i];
        }
        reverse(ans.begin(), ans.end());
    }
    else{
        ans += str[len/2];
        for(int i=(len/2)-1, j=(len/2)+1; i>=0; i--, j++){
            ans += str[j];
            ans += str[i];
        }
    }
    
    cout << ans << endl;
    return 0;
}