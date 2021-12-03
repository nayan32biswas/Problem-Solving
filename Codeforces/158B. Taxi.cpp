#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, i, temp, J;
    int one = 0, two = 0, three = 0, ans = 0;
    cin>>n;
    for(i=0; i<n; i++){
        scanf("%d", &temp);
        if(temp==4) ans++;
        else if(temp==3) three++;
        else if(temp==2) two++;
        else one++;
    }
    ans+=(two/2);
    if(two&1) two=1;
    else two=0;
    if(three==one){
        ans+=one;
        three = 0;
        one = 0;
    }
    else {
        if(three<one){
            ans+=three;
            one-=three;
            three = 0;
        }
        else {
            ans+=one;
            three-=one;
            one = 0;
        }
    }
    if(three>0) ans+=three;
    if(two>0)one+=2;
    if(one>0){
        ans+=(one/4);
        if(one%4!=0)ans++;
    }
    cout<<ans<<endl;
    return 0;
}
