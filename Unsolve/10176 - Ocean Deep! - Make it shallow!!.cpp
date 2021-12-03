#include <iostream>
#include <math.h>
#include <cstdio>
using namespace std;
int main()
{
    freopen("input.txt","r",stdin);
    char bi[10050], c;
    int Dec, i=0, n, l, j, temp;
    while(2){
        while(1) {
            scanf("%c",&c);
            if(c == '#') break;
            bi[i] = c;
            i++;
        }
        Dec = 0;
        for(j=i-1,l=0; j>=0; j--,l++) {
            n = bi[j]-'0';
            n *= pow(2,l);
            Dec+=n;
        }
        if(Dec==0 || Dec==1) printf("YES\n");
        else if(Dec%131071==0) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
