#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    char c;
    int a, b, d, i, j, ans, k=0;
    cin>>a>>b>>d;
    if(d&1){
        c='L';
        ans=1;
        for(i=1; i<=a; i++){
            k=0;
            for(j=1; j<=b; j++){
                if(ans==d){
                    k=1;
                    break;
                }
                ans+=2;
            }
            if(k==1) break;
        }
    }
    else{
        ans=2;
        c='R';
        for(i=1; i<=a; i++){
            k=0;
            for(j=1; j<=b; j++){
                if(ans==d){
                    k=1;
                    break;
                }
                ans+=2;
            }
            if(k==1) break;
        }
    }
    cout<<i<<' '<<j<<' '<<c<<endl;

}
