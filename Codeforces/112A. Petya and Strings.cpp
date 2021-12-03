#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main()
{
    char a[150], b[150];
    cin>>a>>b;
    int len, len1;
    len = strlen(a);
    len1 = strlen(b);
    for(int i=0; i<len; i++){
        if(a[i]<95) a[i]+=32;
    }
    for(int i=0; i<len1; i++){
        if(b[i]<95) b[i]+=32;
    }
    printf("%d\n",strcmp(a,b));

    return 0;
}
