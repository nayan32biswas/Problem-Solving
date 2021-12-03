#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin>>n>>k;
    if(k>n) return puts("-1"), 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++){
            if(i!=j || k<1) printf("0 ");
            else{
                printf("1 ");
                k--;
            }
        }
        puts("");
    }
    return 0;
}
