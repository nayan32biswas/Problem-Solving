#include <bits/stdc++.h>
using namespace std;
#define Size 1001
int arr[Size+1];
int mark[Size+1];
int Find(int a){
    memset(mark, 0, sizeof(mark));
    mark[a]++;
    while(true){
        if(mark[a]==2){
            return a;
        }
        a = arr[a];
        mark[a]++;
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        scanf("%d", &arr[i]);
    }
    for(int i=1; i<=n; i++){
        printf("%d ", Find(i));
        //for(int j=1; j<=n; j++)cout<<mark[j]<<" ";puts("");
    }
    puts("");
    return 0;
}
