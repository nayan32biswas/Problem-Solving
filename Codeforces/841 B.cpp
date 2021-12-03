#include <bits/stdc++.h>
using namespace std;
int x, odd, even;
int main()
{
    int n, i;
    cin>>n;
    for(i=0; i<n; i++){
        scanf("%d", &x);
        if(x&1) odd++;
        else even++;
    }
    if(odd==0) return puts("Second"), 0;
    puts("First");
    return 0;
}
