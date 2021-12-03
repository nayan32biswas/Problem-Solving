#include <bits/stdc++.h>
using namespace std;
#define ans(n) printf("There are %d black pixels.\n", n)
char p = 'p', f = 'f';
char segt[1500];
int pos, len;
void bild(int root, string str, int len) {
    if(pos<len) {
        root*=4;
        for(int i=1; i<5 && pos<len; i++, pos++) {
            if(segt[root+i]!=f) {
                if(str[pos]==f)
                    segt[root+i] = f;
                else if(str[pos]==p) {
                    segt[root+i] = p;
                    pos++;
                    bild(root+i, str, len);
                    pos--;
                }
            }
        }
    }
}
int Find(int root, int depth) {
    if(segt[root]==0)
        return 0;
    if(segt[root]==f)
        return depth;
    depth/=4;
    root *= 4;
    int ans = 0;
    for(int i=1; i<5; i++)
        if(segt[root+i])
            ans += Find(root+i, depth);

    return ans;
}
int main() {
    int test;
    string A, B;
    cin>>test;
    while(test--) {
        cin>>A>>B;
        if(A[0]==f || B[0]==f) {
            ans(1024);
            continue;
        }
        memset(segt, 0, sizeof(segt));
        segt[0] = p;
        if(A[0]==p)
            pos=1, bild(0, A, A.size());
        if(A[0]==p)
            pos=1, bild(0, B, B.size());
        ans(Find(0, 1024));
    }
    return 0;
}

