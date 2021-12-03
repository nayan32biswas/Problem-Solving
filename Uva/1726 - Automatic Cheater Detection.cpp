#include <bits/stdc++.h>
using namespace std;
int arr[11], brr[11];
int main()
{
    //freopen("input.txt", "r", stdin);
    int test, d, r, Q, ans, sum;
    char c;
    cin>>test;
    while(test--){
        scanf("%d", &Q);
        memset(arr, 0, sizeof(arr));
        memset(brr, 0, sizeof(brr));
        while(Q--){
            scanf("%d%d %c", &d, &r, &c);
            if(r==0 && c=='i') arr[d]++;
            else if(r==1 && c=='c') brr[d]++;
        }
        ans = sum = 0;
        for(int i=10; i>1; i--){
            sum+=brr[i];
            ans+=(sum*arr[i-1]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
