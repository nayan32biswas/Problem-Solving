#include <bits/stdc++.h>
using namespace std;
#define Size 1000
int arr[Size];
int main()
{
    //freopen("input.txt", "r", stdin);
    long long n, h, a, b, k, ans;
    long long taa, faa, tbb, fbb;
    scanf("%lld%lld%lld%lld%lld", &n, &h, &a, &b, &k);
    for(int i=0; i<k; i++){
        scanf("%lld%lld%lld%lld", &taa, &faa, &tbb, &fbb);
        if(taa==tbb){
            printf("%d\n", abs(faa-fbb));
            continue;
        }
        ans = 0;
        if(faa<a){
            ans += abs(a-faa);
            faa = a;
        }
        else if(faa>b){
            ans += abs(faa-b);
            faa = b;
        }

        if(fbb<a){
            ans += abs(a-fbb);
            fbb = a;
        }
        else if(fbb>b){
            ans += abs(fbb-b);
            fbb = b;
        }

        ans += abs(faa-fbb);
        ans += abs(taa-tbb);

        if(taa==tbb){
            ans = abs(faa-fbb);
        }


        printf("%lld\n", ans);
    }
    return 0;
}
