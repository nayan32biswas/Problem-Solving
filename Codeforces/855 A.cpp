#include <bits/stdc++.h>
using namespace std;
map<string, bool> name;

int main()
{
    int n;
    cin>>n;
    string s;
    while(n--){
        cin.ignore();
        cin>>s;
        if(name[s])puts("YES");
        else puts("NO");
        name[s] = 1;
    }
    return 0;
}
