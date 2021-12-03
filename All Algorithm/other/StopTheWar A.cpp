#include <bits/stdc++.h>
using namespace std;
#define Size 50
int arr[Size];
int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        int ans = n/3;
        if(n%3) ans++;
        printf("%d\n", ans);
    }
    return 0;
}
