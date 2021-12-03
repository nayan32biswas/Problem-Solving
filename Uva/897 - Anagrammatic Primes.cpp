#include <bits/stdc++.h>
using namespace std;
/**
Hacking solution
int ans[] = {2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 113, 131, 199, 311, 337, 373, 733, 919, 991};
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    while(scanf("%d", &n) && n!=0){
        if((n>=7 && n<10) || (n>=97 && n<100) || n>=991) puts("0");
        else for(int i=0; i<22; i++){
                if(ans[i]>n){
                    printf("%d\n", ans[i]);
                    break;
                }
            }
    }
    return 0;
}*/

#define Size 10000020

string to_String(int n){
    string ans="";
    while(n>0){
        ans+=(char)(n%10);
        n/=10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int to_int(string s){
    int ans = 0;
    for(auto c : s){
        ans = (ans*10)+c;
    }
    return ans;
}

int pri[(Size>>5)];
bool mark[Size];
vector<int>prime(22);
#define Check(n) (pri[n>>6] & (1<<((n>>1)&31)))
#define Set(n) (pri[n>>6] |= (1<<((n>>1)&31)))
#define isp(n) ((n==2) || (n>1 && (n&1) && !Check(n)))

void Next(int n, int &j){
    vector<int>V;
    string s = to_String(n);
    sort(s.begin(), s.end());
    int num;
    string temp = s;
    do {
        for(auto c : s)if(c%2==0) return;

        num = to_int(s);
        if(!isp(num) || num<n) return;
        V.push_back(num);
    } while(next_permutation(s.begin(), s.end()));

    for(auto v : V) {
        mark[v] = 1;
        prime[j++] = v;
    }
}
void seive(){
    int i, j, root = ceil(sqrt(Size))+1;
    for(i=3; i<root; i+=2){
        if(!Check(i)){
            for(j=i*i; j<Size; j+=(i<<1)) Set(j);
        }
    }
    prime[0] = 2;
    for(i=3, j=1; i<Size; i+=2)if(!Check(i) && !mark[i]){
        Next(i, j);
    }
    sort(prime.begin(), prime.end());
}
int main(){
    //freopen("input.txt", "r", stdin);
    seive();
    int n, num, End;
    vector<int>::iterator it;
    while(scanf("%d", &n) && n!=0){
        End = 1, num = n;
        while(num>0){
            End*=10;
            num/=10;
        }
        n++;
        it = lower_bound(prime.begin(), prime.end(), n);
        num = prime[it-prime.begin()];
        if(num>End || (num<0 || num>Size)) puts("0");
        else printf("%d\n", num);
    }
}

