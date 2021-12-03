#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[1009], x, n, i;
    cin>>n;
    for(i=0; i<n; i++){
        scanf("%d%d", &arr[i], &x);
        if(arr[i]!=x) {
            puts("rated");
            return 0;
        }
    }
    bool ck=true;
    n--;
    if(arr[0]<arr[1]) return puts("unrated"), 0;
    else {
        for(i=0; i<n; i++){
            if(arr[i]>=arr[i+1]) continue;
            else return puts("unrated"), 0;
        }
    }

    puts("maybe");
    return 0;
}
