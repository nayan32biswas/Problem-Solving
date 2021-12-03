#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int main()
{
    int n, x, cou=0, temp, i, j;
    scanf("%d%d", &n, &x);
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    for(i=0; i<n; i++){
        for(j=i; j<n; j++){
            if((arr[i]^arr[j])==x){
                cou++;
            }
        }
    }
    printf("%d\n", cou);
    return 0;
}

