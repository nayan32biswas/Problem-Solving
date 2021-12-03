#include <cstdio>
#include <iostream>
using namespace std;
int arr[100009];
int main()
{
    //freopen("input.txt", "r", stdin);
    int test, n, i, j, temp, ans;
    scanf("%d", &test);
    while(test--) {
        scanf("%d", &n);
        temp = 1;
        for(i=0; (temp==1 && i<n); i++) {
            scanf("%d", &temp);
        }
        arr[0]=0, j=0;
        while(i<n) {
            scanf("%d", &temp);
            if(arr[j]==0) {
                j++;
                arr[j]=temp;
            }
            else if(temp==0){
                j++;
                arr[j]=temp;
            }
            i++;
        }
        arr[j]==1 ? n=j : n=j+1;
        for(i=0, ans=0; i<n; i++) {
            if(arr[i]==1) ans++;
        }
        n-=(ans+2);
        if(n>0)ans = ans+n;
        //cout<<ans<<endl;
        if(ans&1) puts("Alice");
        else puts("Bob");
    }
    return 0;
}
