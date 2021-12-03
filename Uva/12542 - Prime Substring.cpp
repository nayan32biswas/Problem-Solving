#include <bits/stdc++.h>
#define SIZE 100000
using namespace std;
unsigned pri[(SIZE>>6)+5];
string prime[10000];
#define Check(n) (pri[n>>6] & (1<<((n>>1)&31)))
#define Set(n) (pri[n>>6] |= (1<<((n>>1)&31)))
void to_string(int n, int j){
    char i = (n%10)+48;
    n/=10;
    if(n) to_string(n, j);
    prime[j]+=i;
}
void seive()
{
    int i, j, root= ceil(sqrt(SIZE)+1);
    for(i=3; i<root; i+=2)if(!Check(i)){
        for(j=i*i; j<SIZE; j+=(i<<1)) Set(j);
    }
    prime[0]='2';
    for(i=3, j=1; i<SIZE; i+=2)if(!Check(i)){
        to_string(i, j++);
    }
}
int len, len1;
int KMP(string test, string pattern) {
    int i, j;
    len = pattern.size();
    if(len>len1) return -1;
    int temp[len];
    for(i=1, j=0, temp[0]=0; i<len; ){
        if(pattern[i]==pattern[j]){temp[i++] = ++j;}
        else if(j==0) temp[i++]=0;
        else j=temp[j-1];
    }
    for(i=0, j=0; i<len1 && j<len; ) {
        if(pattern[j]==test[i]){i++, j++;}
        else if(j==0) i++;
        else j=temp[j-1];
    }
    if(j==len) return 1;
    return 0;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    seive();
    int n, i;
    string s, s1;
    while(cin>>s){
        len1 = s.size();
        if(len1==1 && s[0]=='0') return 0;
        for(i=9591; i>=0; i--)if(prime[i].size()<=len1) break;
        for(; i>=0; i--){
            if(KMP(s, prime[i])){
                cout<<prime[i]<<endl;
                break;
            }
        }
    }
}
/// 9592
