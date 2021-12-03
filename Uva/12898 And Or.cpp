#include <bits/stdc++.h>
using namespace std;
string to_bit(long long n){
    string s="";
    while(n>0){
        if(n&1) s+='1';
        else s+='0';
        n>>=1;
    }
    reverse(s.begin(), s.end());
    return s;
}
unsigned long long to_long(string s){
    unsigned long long num=0, x=1;
    reverse(s.begin(), s.end());
    for(auto it : s){
        if(it=='1')num+=x;
        x<<=1;
    }
    return num;
}
int main(){
    //freopen("input.txt", "r", stdin);
    long long a, b;
    int test, len;
    string A, B, OR, AND;
    cin>>test;
    for(int t=1; t<=test; t++){
        scanf("%lld%lld", &a, &b);
        printf("Case %d: ", t);
        A = to_bit(a);
        B = to_bit(b);
        OR = AND = "";
        len = B.size();
        if(A.size()<B.size()){
            for(int i=0; i<len; i++) OR+='1';
            len--;
            AND+='0';
            printf("%lld %lld\n", to_long(OR), to_long(AND));
        }
        else {
            int x;
            for(int i=0; i<len; i++){
                if(A[i]==B[i])OR+=A[i];
                else break;
                x = i;
            }
            AND+=OR;
            for(int i=x; i<len; i++) OR+='1';
            for(int i=x; i<len; i++) AND+='0';
            printf("%lld %lld\n", to_long(OR)>>1, to_long(AND)>>1);
        }

    }
    return 0;
}
