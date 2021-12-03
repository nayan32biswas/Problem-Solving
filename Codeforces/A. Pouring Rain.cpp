#include <bits/stdc++.h>
#define p acos(-1)
using namespace std;
int main()
{
    double d, h, v, e;
    cin>>d>>h>>v>>e;
    v = v/(p*d*d/4);
    if(v-e<0)puts("NO");
    else{
        puts("YES");
        cout<<h/(v-e)<<endl;
    }
    return 0;
}
