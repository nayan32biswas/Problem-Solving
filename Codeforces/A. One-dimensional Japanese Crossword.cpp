#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int>ans;
int main()
{
    int n, temp, i;
    char s[109];
    scanf("%d%s", &n, s);
    for(i=0, temp=0; i<n; i++) {
        if(s[i]=='B') temp++;
        else if(s[i]=='W') {
            if(temp>0) ans.push_back(temp);
            temp = 0;
        }
    }
    if(temp>0) ans.push_back(temp);
    cout<<ans.size()<<endl;
    for(i=0; i<ans.size(); i++) {
        if(i) cout<<' ';
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}
