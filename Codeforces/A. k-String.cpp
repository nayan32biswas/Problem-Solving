#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int a[256]={0}, k, n, l, ll;
    char ans[1000]={""};
    scanf("%i",&n);  getchar();
    while((k=getchar())!='\n')a[k]++;

    for(l=0, k='a';k<='z';k++){
        if(a[k]%n){puts("-1");return 0;}
        ll=a[k]/n;
        while(ll--)ans[l++]=k;
    }
    while(n--)printf("%s",ans);
    return 0;
}
