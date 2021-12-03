#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ppi;
typedef vector<ppi> vec;
typedef unsigned long long ull;
#define Size 32769
unsigned pri[(Size>>6)+5];
vector<int>prime(Size/4);
#define Set(n) (pri[n>>6] |= (1<<((n>>1)&31)))
#define Check(n) (pri[n>>6] & (1<<((n>>1)&31)))

ull Pow(int x, int i);
ull to_int(string str);
void seive();
void print(vec ans);
void Find(ull n);

int main() {
    seive();
    string str;
    ull n;
    while(getline(cin, str) && str.size()>1) {
        n = to_int(str);
        Find(n);
    }
}
ull to_int(string str) {
    bool check=true;
    ull n=1, x, temp=0;
    for(auto it : str) {
        if(it==' ') {
            if(check) {
                x = temp;
                temp = 0;
                check = false;
            } else {
                n *= Pow(x, temp);
                temp = 0;
                check = true;
            }
        } else {
            temp = (temp*10)+(it-'0');
        }
    }
    if(temp>0)
        n *= Pow(x, temp);
    return n-1;
}
ull Pow(int x, int i) {
    ull n=1;
    while(i--)
        n*=x;
    return n;
}
void print(vec ans) {
    int i=0;
    sort(ans.begin(), ans.end(), greater<ppi>());
    for(auto it : ans) {
        if(i++)
            printf(" ");
        printf("%d %d",it.first, it.second);
    }
    puts("");
}
void Find(ull n) {
    vec ans;
    int coun;
    for(int i=0, x=prime[i]; x*x<=n; i++, x=prime[i]) {
        coun = 0;
        while(n%x==0) {
            coun++;
            n /= x;
        }
        if(coun)
            ans.push_back(make_pair(x, coun));
    }
    if(n>1)
        ans.push_back(make_pair(n, 1));
    print(ans);
}
void seive() {
    for(int i=3; i*i<=Size; i+=2)
        if(!Check(i)) {
            for(int j=i*i; j<Size; j+=(i*2))
                Set(j);
        }
    prime[0]=2;
    for(int i=3, j=1; i<Size; i+=2)
        if(!Check(i))
            prime[j++] = i;
}
