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
int store[1000009], iii;

int main()
{
    //freopen("input.txt", "r", stdin);
    int arr[1009], i, j, n, m, test=0, t, num;
    while(scanf("%d", &n)==1 && n){
        printf("Case %d:\n", ++test);
        for(i=0; i<n; i++)read(arr[i]);
        for(i=0, iii=0; i<n-1; i++){
            for(j=i+1; j<n; j++) store[iii++]=arr[i]+arr[j];
        }sort(store, store+iii);
        //for(i=0; i<iii; i++)cout<<store[i]<<' ';cout<<endl;

        scanf("%d", &m);
        for(t=0; t<m; t++){
            scanf("%d", &num);
            printf("Closest sum to %d is ", num);
            if(num<=store[0])printf("%d", store[0]);
            else if(num>=store[iii-1])printf("%d", store[iii-1]);
            else{
                for(i=0; i<iii; i++)if(store[i]>num)break;
                if(abs(store[i]-num)<abs(store[i-1]-num)) printf("%d", store[i]);
                else printf("%d", store[i-1]);
            }
            puts(".");
        }
    }
    return 0;
}
