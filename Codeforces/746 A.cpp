#include <iostream>
using namespace std;

int call(int l, int a, int p)
{
    if(l==0 || ((l<<1)<=a && (l<<2)<=p)){
        return l;
    }
    call(--l, a, p);
}

int main()
{
    int l, a, p, ans, len;
    cin>>l>>a>>p;
    len = l;
    l = call(l, a, p);
    if(l!=0)
        ans = (l<<1)+(l<<2)+l;
    else
        ans=0;
    cout<<ans<<endl;
    return 0;
}
