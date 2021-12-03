#include <bits/stdc++.h>
using namespace std;
#define Size 5
string tostr(int n) {
    string str;
    while(n) {
        str += ((n%10)+48);
        n/=10;
    }
    while(str.size()<Size)
        str += '0';
    reverse(str.begin(), str.end());
    return str;
}
bool isUnic(int x, int y) {
    bool mark[10];
    memset(mark, 0, sizeof(mark));
    if(y<10000)
        mark[0] = 1;
    int ttt;
    while(x || y) {
        if(x) {
            ttt = x%10;
            if(mark[ttt])
                return false;
            mark[ttt] = 1;
            x /= 10;
        }
        if(y) {
            ttt = y%10;
            if(mark[ttt])
                return false;
            mark[ttt] = 1;
            y/=10;
        }
    }
    for(int i=0; i<10; i++)
        if(!mark[i])
            return false;

    return true;
}
int main() {
    int n, test=0;
    while(scanf("%d", &n) && n) {
        bool ck = false;
        int x = 10000, y = 1000, ttt;
        if(test++)
            puts("");
        while(x<99999 && y<99999) {
            ttt = x/y;
            if(ttt==n && x%y==0 && isUnic(x, y)) {
                cout<<tostr(x)<<" / "<<tostr(y)<<" = "<<n<<endl;
                ck = true;
            }
            if(ttt<n)
                x++;
            else
                y++;
        }
        if(!ck)
            printf("There are no solutions for %d.\n", n);
    }

    return 0;
}
