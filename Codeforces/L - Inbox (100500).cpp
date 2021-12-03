#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, past=0, now, ans=0;
    cin>>n;
    while(n--){
        scanf("%d", &now);
        if(now) {
            if(past) ans++;
            else ans+=2;
        }
        past = now;
    }
    if(!ans) ans++;
    cout<<ans-1<<endl;
    return 0;
}
