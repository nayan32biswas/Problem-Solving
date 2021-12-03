#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int time, n, lo=INT_MAX, city=0;
    cin>>n;
    for(int i=1; i<=n; i++){
        scanf("%d", &time);
        if(time<lo){
            lo = time;
            city = i;
        }
        else if(lo==time){
            city = 0;
        }
    }
    if(city == 0){
        cout<<"Still Rozdil"<<endl;
    }
    else cout<<city<<endl;
    return 0;
}
