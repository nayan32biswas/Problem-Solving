#include <bits/stdc++.h>
using namespace std;
#define Size 1001
typedef pair< int, int > ppi;
int divisors(int n){
    if(n==1) return 1;
    int i, coun=2, num=n, root = sqrt(ceil(n))+1;
    for(i=2; i<root; i++){
        if(num%i==0) coun+=2;
        if(i*i==num) return coun-1;
    }
    return coun;
}
ppi arr[Size];
int ans[Size];
int main()
{
    freopen("input.txt", "r", stdin);
    int test, i, j, n;
    for(i=1; i<Size; i++){
        arr[i].first = divisors(i);
        arr[i].second = i;
    }
    for(i=1; i<Size; i++)
        for(j=i+1; j<Size; j++)
            if(arr[i].first>=arr[j].first) swap(arr[i], arr[j]);
    for(i=0; i<Size; i++) ans[arr[i].second] = i;

    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        scanf("%d", &n);
        printf("Case %d: ", t);
        cout<<ans[n]<<endl;
    }

}
