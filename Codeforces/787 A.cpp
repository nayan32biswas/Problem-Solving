#include <bits/stdc++.h>
#define LMT 100000000
using namespace std;
int main()
{
    unsigned long long a, b, c, d, temp, temp1, i, J;
    cin>>a>>b>>c>>d;
    if(b==d){
        cout<<b<<endl;
        return 0;
    }
    i = 1, J=1;
    temp = b, temp1 = d;
    while(temp<LMT && temp1<LMT) {
        if(temp1==temp){
            cout<<temp<<endl;
            return 0;
        }
        while(temp<temp1) {
            temp=b+(a*i);
            i++;
        }
        while(temp1<temp) {
            temp1=d+(c*J);
            J++;
        }
    }
    puts("-1");
    return 0;
}
