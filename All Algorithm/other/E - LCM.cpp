#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x)
{
    char c;
    bool t=false;
    for(c=getchar(); (c<'0'||c>'9') && c!='-'; c=getchar());
    if(c=='-'){c=getchar(); t=true;}
    for(x=c-'0', c=getchar(); c>='0'&&c<='9'; x=x*10+c-'0', c=getchar());
    if(t) x=-x;
}
#define SIZE 100000090
#define MAX 4294967296
unsigned pri[(SIZE>>6)+5];
unsigned prime[6666666];
#define Check(n) (pri[n>>6] & (1<<((n>>1)&31)))
#define Set(n) (pri[n>>6] |= (1<<((n>>1)&31)))
void seive(){
    int i, j, root = ceil(sqrt(SIZE))+1;
    for(i=3, Set(1); i<root; i+=2)if(!Check(i)){
        for(j=i*i; j<SIZE; j+=(i<<1)) Set(j);
    }
    for(prime[0]=2, i=3, j=1; i<SIZE; i+=2)if(!Check(i)){
        prime[j++]=i;
    }
}
bool isPrime(int num){
    if(num==2) return true;
    if(!(num&1)) return false;
    return !Check(num);
}
long long LCM(int num){
    int i, p;
    bool ck;
    long long lcm=1, temp;
    for(i=0; prime[i]<=num; i++){
        p = prime[i];
        temp = p;
        ck=true;
        while(temp*p<=num) temp*=p, ck=false;
        if(ck){
            for(; prime[i]<=num; lcm*=prime[i], lcm%=MAX, i++);
            return lcm;
        }
        lcm*=temp;
        lcm%=MAX;
    }
    return lcm;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    seive();
    int i, j, test, n;
    long long ans;
    read(test);test++;
    for(int t=1; t<test; t++){
        read(n);
        printf("Case %d: %lld\n", t, LCM(n));
    }
    return 0;
}
