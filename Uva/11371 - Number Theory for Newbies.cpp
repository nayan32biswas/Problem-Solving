#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long to_int(string s) {
    int len, i;
    long long dis;
    len = s.size();
    for(i=0, dis=0; i<len; i++) {
        dis = (dis*10)+(s[i]-48);
    }
    return dis;
}
int main() {
    //freopen("input.txt", "r", stdin);
    long long num, dis, mult;
    int len, i;
    string s, s1;
    while(cin>>s){
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());
        num = to_int(s);
        len = s.size()-1;
        s1.clear();
        if(s[len]=='0'){
            for(i=len; i>=0; i--) {
                s1+=s[i];
                if(s[i]!=48) break;
                s.erase(i);
            }
            s.erase(i);
            reverse(s.begin(), s.end());
            reverse(s1.begin(), s1.end());
            s1+=s;
            dis=to_int(s1);
        }
        else {
            num = to_int(s);
            reverse(s.begin(), s.end());
            dis = to_int(s);
        }
        if(dis<num) swap(dis, num);
        mult = dis-num;
        printf("%lld - %lld = %lld = 9 * %lld\n", dis, num, mult, mult/9);
    }
    return 0;
}
