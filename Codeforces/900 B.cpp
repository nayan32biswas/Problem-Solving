#include <bits/stdc++.h>
using namespace std;
#define Size 1000
map<int, bool>X, Y;
int main()
{
    double a, b;
    int c, past, ans=0;
    cin>>a>>b>>c;

    double x = a/b;

    string s = to_string(a/b);
    for(auto it : s){
        ans++;
        if(it-'0'==c){
            cout<<ans<<endl;
            return 0;
        }
    }

    puts("-1");
    return 0;
}

