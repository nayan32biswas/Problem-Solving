#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int arr[200009];
int main()
{
    int i, n, ans, dis, temp;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    sort(arr, arr+n);
    ans = 0, dis = INT_MAX;
    for(i=1; i<n; i++) {
        temp = abs(arr[i]-arr[i-1]);
        if(temp==dis)ans++;
        else if(dis>temp){
            ans = 1;
            dis = temp;
        }
    }
    printf("%d %d\n", dis, ans);
}
