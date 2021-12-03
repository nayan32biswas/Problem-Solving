#include <bits/stdc++.h>
using namespace std;
#define Size 1000009
int arr[Size];
int ans[10][Size];
int test, l, r, k;
int fff(int n) {
    int x = 1;
    while(n) {
        if(n%10)
            x *= n%10;
        n/=10;
    }
    return x;
}
int ggg(int n) {
    if(n<10)
        return n;
    return ggg(fff(n));
}
int main() {
    for(int i=1; i<Size; i++)
        arr[i] = ggg(i);
    for(int i=1; i<10; i++) {
        int x = 0;
        for(int j=1; j<Size; j++) {
            if(arr[j]==i)
                x++;
            ans[i][j] = x;
        }
    }
    cin>>test;
    while(test--) {
        cin>>l>>r>>k;
        cout<<ans[k][r]-ans[k][l-1]<<endl;
    }
    return 0;
}
