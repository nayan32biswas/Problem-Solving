#include <bits/stdc++.h>
using namespace std;
#define Size 200
bool arr[3];
bool check(int x){
    if(!arr[x]) return true;
    for(int i=0; i<4; i++)if(i!=x){
        arr[i] = !arr[i];
    }
    return false;
}
int main()
{
    int n, x;
    arr[1] = arr[2] = 1;
    cin>>n;
    while(n--){
        cin>>x;
        if(check(x))return puts("NO");
    }
    puts("YES");

    return 0;
}
