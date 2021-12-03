#include <bits/stdc++.h>
using namespace std;
#define Size 10000
int arr[Size], N, temp;
bool Find(int x){
    for(int i=1; (i<<1)+x<N; i++){
        //cout<<x-(i<<1)<<" "<<x-i<<" "<<x<<" "<<x+i<<" "<<(i<<1)+x<<endl;
        if(arr[x]<arr[i+x]){
            if(arr[i+x]<arr[(i<<1)+x]){
                return true;
            }
        }
        else if(x-(i<<1)>=0 && arr[x]>arr[x-i] && arr[x-i]>arr[ x-(i<<1) ]){
            return true;
        }
    }
    return false;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    while(scanf("%d", &N) && N){
        getchar();
        for(int i=0; i<N; i++){
            scanf("%d", &temp);
            arr[temp] = i;
        }
        bool ans = true;
        for(int i=0; i<N-2; i++){
            if(Find(i)){
                ans = false;
                break;
            }
        }
        puts(ans ? "yes" : "no");
    }
    return 0;
}


