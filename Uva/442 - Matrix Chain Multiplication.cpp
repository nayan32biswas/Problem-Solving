#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef pair<lli, lli> pii;
map<char, pii>data;
void Find(stack<pii>&stk, lli &ans) {
    lli n1, n2, m1, m2;
    n2 = stk.top().first;
    m2 = stk.top().second;
    stk.pop();
    if(stk.empty()) {
        stk.push(make_pair(n2, m2));
        return;
    }
    n1 = stk.top().first;
    m1 = stk.top().second;
    stk.pop();
    if(m1!=n2) {
        stk.push(make_pair(0, 0));
        return;
    }
    ans += (n1*m1*m2);
    stk.push(make_pair(n1, m2));
}

void solve(string &str) {
    stack<pii>stk;
    lli ans = 0;
    for(auto it : str) {
        if(it == ')') {
            Find(stk, ans);
            if(stk.top().first==0) {
                puts("error");
                return;
            }
        }
        if(isalpha(it)) {
            stk.push(data[it]);
        }
    }
    while(stk.size()>1) {
        Find(stk, ans);
        if(stk.top().first==0) {
            puts("error");
            return;
        }
    }
    printf("%lld\n", ans);
}
int main() {
    //freopen("input.txt", "r", stdin);
    char ch;
    int n, x, y;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        cin>>ch;
        scanf("%d%d", &x, &y);
        //cout<<ch<<" "<<x<<" "<<y<<endl;
        data[ch] = make_pair(x, y);
    }
    string str;
    while(cin>>str) {
        solve(str);
    }
    return 0;
}
