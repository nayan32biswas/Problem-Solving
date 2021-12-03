#include <bits/stdc++.h>
using namespace std;
int arr[100009];
int main()
{
    int gcd, N, M, x, y;
    cin>>N>>M;
    cin>>gcd;
    arr[0] = gcd;
    for(int i=1; i<N; i++){
        scanf("%d", &arr[i]);
        gcd = __gcd(arr[i], gcd);
    }
    while(M--){
        scanf("%d%d", &x, &y);
        x--;
        arr[x] = arr[x]/y;
        gcd = __gcd(gcd, arr[x]);
        cout<<gcd<<endl;
    }
    return 0;
}
