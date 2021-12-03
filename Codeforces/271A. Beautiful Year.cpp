#include <iostream>
using namespace std;
int main()
{
    int Y, i, a, b, c, d;
    cin>>Y;
    for(i=Y+1; i<9020; i++){
        Y = i;
        a = Y%10;
        Y /=10;
        b = Y % 10;
        Y/=10;
        c = Y % 10;
        d = Y/10;
        if(a==b || a==c || a==d || b==c || b==d || c==d) continue;
        else break;
    }
    cout<<i<<endl;
    return 0;
}
