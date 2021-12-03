#include <bits/stdc++.h>
using namespace std;
vector<int>arr;
void Remove(int i){
    i--;
    arr.erase(arr.begin()+i, arr.begin()+i+1);
}
int main()
{
    int test, k, n;
    cin>>test;
    for(int t=1; t<=test; t++){
        scanf("%d%d", &n, &k);
        arr.clear();
        for(int i=1; i<=n; i++) arr.push_back(i);
        int i = k, len = n;
        while(len!=1){
            i%=len;
            if(!i) i=len;
            Remove(i);
            i--;
            i+=k;
            len = arr.size();

        }
        printf("Case %d: %d\n", t, arr[0]);
    }
    return 0;
}
