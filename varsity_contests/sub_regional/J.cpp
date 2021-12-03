#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    long long int ans = 0, temp;
    int x;
    cin >> s;
    for(int i=0; s[i]; i++){
        //x = s[i]-'0';
        //ans += min(x, 10-x+1);
        ans += s[i]-'0';
    }
    temp = 1;
    for(int i=0; s[i]; i++){
        temp += 10-(s[i]-'0');
    }

    ans = min(temp, ans);
    temp = 0;
    for(int i=0; s[i]; i++){
        x = s[i]-'0';
        temp += min(x, 10-x+1);
    }
    ans = min(temp, ans);

    //cout<<ans<<" "<<temp<<endl;
    cout << min(ans, temp)<< endl;
    return 0;
}
