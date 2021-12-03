#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    vector<int>arr(n), make; 
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int x = 0;
    for(int i=0; i<n; i++){
        if(i==0){
            x=1;
        }
        else{
            if(arr[i-1]==arr[i])x++;
            else{
                make.push_back(x);
                x = 1;
            }
        }
    }
    make.push_back(x);
    int ans = 0;
    for(int i=1; i<make.size(); i++){
        ans = max(ans, min(make[i-1], make[i]));
    }
    cout<<ans*2<<endl;
    return 0;
}