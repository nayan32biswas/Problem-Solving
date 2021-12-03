#include <bits/stdc++.h>
using namespace std;
bool arr[101];
int main()
{
    int n, i, odd=0, x;
    cin>>n;
    i=0;
    if(n&1){
        cin>>x;
        if(x&1) return puts("Yes"), 0;
        arr[x]=1;
        i=1;
    }
    for(; i<n; i++){
        cin>>x;
        if(!arr[x]){
            odd++;
        }
        if(odd>2) return puts("Yes"), 0;
        arr[x]=1;
    }
    puts("No");
}
