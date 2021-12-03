#include <bits/stdc++.h>
using namespace std;
int mark[10000000];
int Find(int r) {
    if(mark[r]==r)
        return r;
    return mark[r] = Find(mark[r]);
}
void convert(string &str, int &x, int &y) {
    x = y = 0;
    int i=2, len = str.size();
    while(i<len && (str[i]>='0' && str[i]<='9')) {
        x = (x*10)+(str[i]-'0');
        i++;
    }
    while(i<len && (str[i]<'0' || str[i]>'9'))
        i++;
    while(i<len && (str[i]>='0' && str[i]<='9')) {
        y = (y*10)+(str[i]-'0');
        i++;
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    int test, n, succ, unsucc, x, y;
    string str;
    cin>>test;
    for(int t=0; t<test; t++) {
        cin>>n;
        for(int i=1; i<=n; i++)
            mark[i] = i;
        succ = unsucc = 0;
        cin.ignore();
        while(getline(cin, str) && str.size()) {
            convert(str, x, y);
            x = Find(x);
            y = Find(y);
            if(str[0]=='c') {
                if(x!=y)
                    mark[x] = y;
            } else {
                if(x==y)
                    succ++;
                else
                    unsucc++;
            }
        }
        if(t)
            puts("");
        printf("%d,%d\n", succ, unsucc);
    }
    return 0;
}
