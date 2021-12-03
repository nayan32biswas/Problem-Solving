#include <bits/stdc++.h>
#define LMT 50009
using namespace std;
struct data{
    int lo, hi;
    bool operator <(const data &X)const{
        return X.lo>lo;
    }
}all[LMT];
int arr[LMT];

int main()
{
    //freopen("input.txt", "r", stdin);
    int test, n, v, ans, i, J;
    bool ck;
    scanf("%d", &test);
    for(int t=1; t<=test; t++) {

        scanf("%d", &n);
        for(i=0; i<n; i++){
            scanf("%d", &arr[i]);
        }
        sort(arr, arr+n);

        scanf("%d", &v);
        for(i=0; i<v; i++) {
            scanf("%d%d", &all[i].lo, &all[i].hi);
        }sort(all, all+v);

        for(i=0, J=0, ans=0; i<v && J<n; i++) {

            while(all[i].hi>=arr[J] && J<n) {
                if(all[i].lo<=arr[J]){
                    ans++;
                }
                J++;
            }
            //printf("%d %d %d %d\n", all[i].lo, all[i].hi, J, ans);
        }
        printf("%d\n", ans);
    }
    return 0;
}
