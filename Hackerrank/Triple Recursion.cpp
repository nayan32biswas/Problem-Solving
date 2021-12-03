#include <bits/stdc++.h>
using namespace std;
#define Size 111
int arr[Size][Size];
int main()
{
    int n, m, k;
    cin>>n>>m>>k;
    int x, y, z;
    for(int i=0; i<n; i++){
        x = m+i*k;
        for(int j=i; j<n; j++) arr[i][j] = arr[j][i] = x--;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j) printf(" ");
            printf("%d", arr[i][j]);
        }
        puts("");
    }
    return 0;
}
