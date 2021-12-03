#include <bits/stdc++.h>
using namespace std;
string A, B;
int len;
bool Find(int i, int hi, int pos) {
    for(int past = i-pos, last = i+pos; i<hi && last<len; i++, past++, last++) {
        //printf("%3d%3d%3d\n", past, i, last);
        if(A[past]==A[i] && A[i]==A[last])
            if(A[i]==B[past] && A[i]==B[i] && A[last]==B[i])
                return true;
    }
    return false;
}
bool Check(int pos) {
    //cout<<pos<<endl;
    for(int i=pos; i+pos+pos<=len; i++)
        if(Find(i, i+pos, pos))
            return true;
    return false;
}
int main() {
    //freopen("input.txt", "r", stdin);
    cin>>A>>B;
    len = min(A.size(), B.size());
    int pos = 1;
    while(pos+pos<len) {
        if(Check(pos))
            return puts("YES")*0;
        pos++;
        //puts("");
    }
    puts("NO");

}
