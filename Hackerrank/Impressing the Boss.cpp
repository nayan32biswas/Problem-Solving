#include <bits/stdc++.h>
using namespace std;
#define Size 21
int arr[Size];
int is_true(int N) {
    for(int i=1; i<N; i++)
        if(arr[i-1]>arr[i])
            return i;
    return -1;
}
string CHECK() {
    int change=0, N;
    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>arr[i];
    }
    int x = is_true(N);
    if(x<0) return "YES";
    int n = arr[x], n1 = arr[x-1];
    arr[x] = arr[x-1] = n;
    if(is_true(N)<0) return "YES";
    arr[x] = arr[x-1] = n1;
    if(is_true(N)<0) return "YES";
    return "NO";
}
int main() {
    //freopen("input.txt", "r", stdin);
    int test, N;
    cin>>test;
    for(int t=1; t<=test; t++) {
        cout<<CHECK()<<endl;
    }
    return 0;
}
