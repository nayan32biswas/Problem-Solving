#include <bits/stdc++.h>
using namespace std;
int arr[200005];
int main() {
    int p, n, lo=0, hi=1;
    char ch;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        getchar();
        scanf("%c %d", &ch, &p);
        if(ch=='L') {
            arr[p] = lo--;
        } else if(ch=='R') {
            arr[p] = hi++;
        } else {
            p = arr[p];
            printf("%d\n", min((p-lo), (hi-p))-1);
        }
    }
    return 0;
}
