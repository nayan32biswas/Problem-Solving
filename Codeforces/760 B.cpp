#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n, m, k, dr, st, f=1, d, s=0;
    scanf("%d%d%d", &n, &m, &k);
    m=m-n;
    if(m==0){
        puts("1");
        return 0;
    }
    dr=n-k;
    st=k-1;
    while((d+s<m) && (d<dr || s<st)){
        m=m-s-d;
        m--;
        if(d<dr)++d;
        if(s<st)++s;
        f++;
    }
    f+=(m/n);
    printf("%d\n", f);
    return 0;
}
