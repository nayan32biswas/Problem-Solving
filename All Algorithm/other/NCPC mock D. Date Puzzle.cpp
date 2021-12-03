#include <bits/stdc++.h>
using namespace std;
int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int solve() {
    int d1, m1, d2, m2;
    scanf("%d%d%d%d", &d1, &m1, &d2, &m2);
    if((d1>12 && m1>12) || (d2>12 && m2>12) || (d1>12 && m2>12) || (m1>12 && d2>12)) {
        return puts("I am sure there is some kinda mistake!");
    }
    if((d1<=12 && mon[d1]<m1) || (m1<=12 && mon[m1]<d1)) {
        return puts("I am sure there is some kinda mistake!");
    }
    if((d2<=12 && mon[d2]<m2) || (m2<=12 && mon[m2]<d2)) {
        return puts("I am sure there is some kinda mistake!");
    }
    if(d1>12 || m1>12 || d2>12 || m2>12 ) {
        if(m1>12 || m2>12){
            swap(d1, m1);
            swap(d2, m2);
        }
        if(m1>m2 || (m1==m2 && d1>d2)){
            puts("I am sure there is some kinda mistake!");
        }
        else{
            puts("Okay got it!");
        }
        return 0;
    }
    if(d1<d2 && m1<m2){
        return puts("Oh no it is ambiguous!");
    }
    return puts("I am sure there is some kinda mistake!");
}
int main() {
    int test;
    cin>>test;
    for(int t=1; t<=test; t++) {
        printf("Case %d: ", t);
        solve();
    }
}
