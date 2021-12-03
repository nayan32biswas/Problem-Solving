#include <bits/stdc++.h>
using namespace std;
int arr[109];
bool triangle(int a, int b, int c){
    if(a<(b+c) && b<(a+c) && c<(a+b)) return true;
    return false;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int N, ans=0;
    cin>>N;
    for(int i=0; i<N; i++) cin>>arr[i];
    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            for(int k=j+1; k<N; k++){
                if(triangle(arr[i], arr[j], arr[k])){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
}
