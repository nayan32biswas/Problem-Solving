#include <bits/stdc++.h>
using namespace std;
int arr[125];
char str[100009], ch;
int main()
{
    int test, ans, len;
    cin>>test;
    for(int t=1; t<=test; t++){
        scanf("%s", str);
        memset(arr, 0, sizeof(arr));
        ans = 1e9;
        for(int i=0; str[i]; i++)arr[str[i]]++;
        for(int i='a'; i<='z'; i++) ans = min(ans, arr[i]);
        printf("Case %d: %d\n",t, ans);
    }
    return 0;
}
