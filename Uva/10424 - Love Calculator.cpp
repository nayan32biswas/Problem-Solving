#include <bits/stdc++.h>
using namespace std;
int one_dig(int sum){
    if(sum<10) return sum;
    int x = 0;
    while(sum>0){
        x+=sum%10;
        sum/=10;
    }
    return one_dig(x);
}
int Sum(string s){
    int sum = 0;
    for(auto c : s){
        if(c>64 && c<91) c-=64;
        else if(c>96 && c<123) c-=96;
        else c = 0;
        sum+=c;
    }
    sum = one_dig(sum);
    return sum;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    string A, B;
    int a, b;
    while(getline(cin, A)){
        getline(cin, B);
        a = Sum(A);
        b = Sum(B);
        if(a<b) swap(a, b);
        if(a==b) puts("100.00 %");
        else {
            double x = a, y = b;
            printf("%.2lf %%\n", (y/x)*100);
        }
    }
    return 0;
}
