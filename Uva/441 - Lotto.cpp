#include <bits/stdc++.h>
using namespace std;
void combination(int arr[], int temp[], int start, int End, int index, int r) {
    if(index == r) {
        for(int i=0; i<r; i++){
            if(i) printf(" ");
            printf("%d", temp[i]);
        }
        printf("\n");
        return;
    }
    for(int i=start; i<=End && End-i+1 >= r-index; i++) {
        temp[index] = arr[i];
        combination(arr, temp, i+1, End, index+1, r);
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    int temp[6], n, t=0;
    while(scanf("%d",&n) && n){
        if(t++) puts("");
        int arr[n];
        for(int i=0; i<n; i++)
            scanf("%d", &arr[i]);
        combination(arr, temp, 0, n-1, 0, 6);
    }
}
