#include <bits/stdc++.h>
using namespace std;
int arr[200009], n;
int Next(int i) {
    for(i++; i<n; i++)if(arr[i]==0) return i;
    return n;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int lo=1, hi, i;
    scanf("%d", &n);
    n++;
    for(i=1; i<n; i++) scanf("%d", &arr[i]);
    hi = Next(0);
    lo = hi;
    for(i=1; i<n; i++){
        if(i==hi) hi = Next(i);
        if(arr[i]==0){
            lo = i;
            hi = Next(i);
            printf("0 ");
        }
        else {
            if(hi!=n) printf("%d ", min(abs(lo-i), abs(hi-i)));
            else printf("%d ", abs(lo-i));
        }
    }
    puts("");
    return 0;

}
