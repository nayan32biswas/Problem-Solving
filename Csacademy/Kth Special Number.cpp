#include <bits/stdc++.h>
using namespace std;
int main()
{
    int k;
    int many=0, i;
    cin>>k;
    for(i=1; i<=33554492; i++){
        int num = i;
        while(num>0){
            if(num&1 && (num>>1)&1) break;
            num>>=1;
        }
        if(num<=0) many++;
        if(many==k)return printf("%d\n", i), 0;
    }
}
