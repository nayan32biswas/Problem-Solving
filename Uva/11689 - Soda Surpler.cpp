#include <bits/stdc++.h>
using namespace std;
int main()
{
    int total, e, f, c, test, restof, ans;
    cin>>test;
    while(test--){
        scanf("%d%d%d", &e, &f, &c);
        total = e + f;
        ans = 0;
        while(total>=c){
            ans += total/c;
            total = ((total%c)+(total/c));

        }
        cout<<ans<<endl;
    }
    return 0;
}
