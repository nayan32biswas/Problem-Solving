#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, a=0, b=0, c=0, temp, s=0;
    long long sum=0;
    cin>>n;
    for(int i=0; i<n; i++) {
        scanf("%d", &temp);
        sum+=temp;
        if(temp>a){
            if(a>b){
                if(b>c){c = b;}
                b = a;
            }
            a=temp;
        }
    }
    if(n<5 && b==0 && c==0) {puts("NO"); return 0;}
    sum-=(a+b);
    if(sum>a){puts("YES"); return 0;}
    else {puts("NO"); return 0;}
    return 0;
}
