#include <bits/stdc++.h>
using namespace std;
bool ck[1000009];
int main()
{
    int i, n, m, h, k, u, v, pos;
    scanf("%d%d%d", &n, &m,&k);
    for(i=0; i<m; i++){
        scanf("%d", &h);
        if(h==1) return puts("1"), 0;
        ck[h]=1;
    }
    for(i=0, pos = 1; i<k; i++) {
        scanf("%d%d", &u, &v);
        if(ck[u] && pos==u) return printf("%d\n",u), 0;
        if(ck[v] && pos==v) return printf("%d\n",v), 0;
        if(pos==u) pos=v;
        else if(pos==v) pos=u;
    }
    cout<<pos<<endl;
    return 0;
}
