#include <bits/stdc++.h>
using namespace std;

template <typename T>
void read(T &x)
{
    char c;
    bool t=false;
    for(c=getchar(); (c<'0'||c>'9') && c!='-'; c=getchar());
    if(c=='-'){c=getchar(); t=true;}
    for(x=c-'0', c=getchar(); c>='0'&&c<='9'; x=x*10+c-'0', c=getchar());
    if(t) x=-x;
}

int arr[200009], ans[200009];
int main(){
    //freopen("input.txt", "r",stdin);
    int i, j, n, k, q, a, b, Ans, x, y;
    scanf("%d%d%d", &n, &k, &q);
    for(i=0; i<n; i++){
        read(a); read(b);
        for(j=a; j<=b; j++) arr[j]++;
    }

    for(i=1, j=0; i<200001; i++){
        if(arr[i]>=k) j++;
        ans[i]=j;
    }
    for(i=0; i<q; i++){
        read(a); read(b);
        a--;
        printf("%d\n", ans[b]-ans[a]);
    }
    return 0;
}
