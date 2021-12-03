#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli big_mod(lli base, lli po, lli mod) {
    lli ans=1;
    while(po>0) {
        if(po&1)
            ans = (ans*base)%mod;
        base=(base*base)%mod;
        po>>=1;
    }
    return ans%mod;
}
bool miillerTest(lli d, lli n) {
    lli a = 2 + rand() % (n - 4);
    lli x = big_mod(a, d, n);
    if (x == 1  || x == n-1)
        return true;
    while (d != n-1) {
        x = (x * x) % n;
        d *= 2;
        if (x == 1)
            return false;
        if (x == n-1)
            return true;
    }
    return false;
}
bool isPrime(lli n) {
    if (n<5) {
        return n==2 || n==3;
    }
    lli d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    lli k = 18; /// high number miens high accuracy
    for (lli i = 0; i < k; i++)
        if (miillerTest(d, n) == false)
            return false;
    return true;
}
void decrease(string& s, int i) {
    if (s[i] <= '2') {
        s.erase(i, 1);
        s[i] = '7';
    } else if (s[i] == '3')
        s[i] = '2';
    else if (s[i] <= '5')
        s[i] = '3';
    else if (s[i] <= '7')
        s[i] = '5';
    else
        s[i] = '7';
    return;
}

string primeDigits(string s) {
    map<char, bool>mark;
    mark['2'] = 1, mark['3'] = 1, mark['5'] = 1, mark['7'] = 1;
    for (int i = 0; i < s.length(); i++) {
        if (!mark[s[i]]) {
            while (s[i] <= '2' && i >= 0)
                i--;
            if (i < 0) {
                i = 0;
                decrease(s, i);
            } else
                decrease(s, i);
            for (int j = i + 1; j < s.length(); j++)
                s[j] = '7';

            break;
        }
    }
    return s;
}
void solve(lli num){
    cout<<num<<" ";
    string str = primeDigits(to_string(num));
    num = stoll(str.c_str());
    cout<<num<<" ";
    while(!isPrime(num)){
        num--;
        str = primeDigits(to_string(num));
        num = stoll(str.c_str());
    }
    printf("%lld\n", num);

}
int main() {
    freopen("input.txt", "r", stdin);
    int test;
    lli num;
    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        scanf("%lld", &num);
        solve(num);
    }
    cout<<clock()<<endl;
    return 0;
}
