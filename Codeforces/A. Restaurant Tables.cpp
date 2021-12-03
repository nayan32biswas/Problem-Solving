#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b, ans=0, t, c=0;
    scanf("%d%d%d", &n, &a, &b);
    for(int i=0; i<n; i++){
        scanf("%d", &t);
        if(t==2){
            if(b>0) b--;
            else ans+=2;
        }
        else{
            if(a>0) a--;
            else if(b>0) b--, c++;
            else if(c>0) c--;
            else ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
