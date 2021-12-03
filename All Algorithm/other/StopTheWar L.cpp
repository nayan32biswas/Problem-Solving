#include <bits/stdc++.h>
using namespace std;
#define Size 100001
long long bit[64];
int arr[Size];
int main()
{
    freopen("input.txt", "r", stdin);
    for(int i=1; i<63; i++){
        bit[i] = (1LL)<<(i-1);
        cout<<bit[i]<<" ";
    }
    puts("");
    int Q, N, l, r, k, X, ans, type;
    long long temp;
    scanf("%d", &N);
    for(int i=1; i<=N; i++)scanf("%d", &arr[i]);
    scanf("%d", &Q);
    while(Q--){
        scanf("%d", &type);
        if(type==1){
            scanf("%d%d", &l, &X);
            arr[l] = X;
        }
        else{
            scanf("%d%d%d", &l, &r, &k);
            ans = 0;
            temp = bit[k];
            for(int i=l; i<=r; i++){
                if(arr[i]&temp){
                    cout<<arr[i]<<" "<<temp<<endl;
                    ans++;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
