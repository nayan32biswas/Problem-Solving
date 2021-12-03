#include <bits/stdc++.h>
using namespace std;
int arr[1000][1000];
int main()
{
    int n, i, j, incre, x;
    scanf("%d", &n);
    incre = sqrt(n);
    for(i=0; i<incre; i++){
        x = incre*i+1;
        for(j=0; j<incre; j++)arr[i][j] = x++;
        x = incre*i+incre*2;
        i++;
        if(i<incre)for(j=0; j<incre; j++)arr[i][j] = x--;
    }
    for(i=0; i<incre; i++){
        for(j=0;j<incre; j++) {
            printf("%d ", arr[i][j]);
        }
        puts("");
    }
    return 0;
}
