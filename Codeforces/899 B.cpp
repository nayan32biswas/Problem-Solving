#include <bits/stdc++.h>
using namespace std;
int month[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, n, arr[25];
bool check(int i){
    for(int j=0; j<n; j++, i++, i%=12){
        if(i==1 && arr[j]==28) continue;
        if(arr[j]!=month[i]) return false;
    }
    return true;
}
int main()
{
    int coun=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        if(arr[i]==29) coun++;
    }
    if(coun>1) return puts("No"), 0;
    for(int i=0; i<12; i++)
        if(check(i))return puts("Yes"), 0;
    puts("No");
    return 0;
}
