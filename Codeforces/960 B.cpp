#include <bits/stdc++.h>
using namespace std;
#define Size 1009
int A[Size], B[Size];
long long dis[Size], ans;
int main()
{
    int n, k1, k2, KK;
    scanf("%d%d%d", &n, &k1, &k2);
    for(int i=0; i<n; i++)scanf("%d", &A[i]);
    for(int i=0; i<n; i++)scanf("%d", &B[i]);
    for(int i=0; i<n; i++){
        dis[i] = abs(A[i]-B[i]);
    }
    KK = k1+k2;
    sort(dis, dis+n);
    reverse(dis, dis+n);
    while(KK>0 && dis[0]){
        dis[0]--, KK--;
        int temp = dis[0];
        for(int i=1; i<n && KK>0 && dis[i]>temp; dis[i]--, i++, KK--);
    }
    if(KK>0){
        if(KK&1) puts("1");
        else puts("0");
        return 0;
    }
    for(int i=0; i<n; i++){
        ans += pow(dis[i], 2);
    }
    cout<<ans<<endl;
    return 0;

}
