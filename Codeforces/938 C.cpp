#include <bits/stdc++.h>
using namespace std;
#define Size 100000
int main() {
    //freopen("input.txt", "r", stdin);
    long long test, n;
    bool check;
    cin>>test;
    while(test--) {
        cin>>n;
        if(n==0)
            puts("1 1");
        else {
            check = false;
            for(long long i=sqrt(n), x = (i*i)-n, p; i<Size; i++, x = (i*i)-n) {
                if(x>0) {
                    p = sqrt(x);
                    if((p*p)==x) {
                        if((i/p)>(i/(p+1))) {
                            cout<<i<<" "<<(i/p)<<endl;
                            check = true;
                            break;
                        }
                    }
                }
            }
            if(check==false)
                puts("-1");
        }
    }
    return 0;
}
