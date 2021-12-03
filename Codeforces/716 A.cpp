#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int ans=1, n, past, t, c;
    cin>>n>>c;
    scanf("%d", &past);
    for(int i=1; i<n; i++) {
        scanf("%d", &t);
        if(t-past>c){
            ans = 1;
        }
        else ans++;
        past = t;
    }
    cout<<ans<<endl;
    return 0;
}
