#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<iostream>
#define m 100000
using namespace std;
int main()
{
    int n,i,j,a[m];
    while(scanf("%d",&n)!=EOF){
        for(i=0; i<n; i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        for(j=0; j<n; j++){
            if(a[j]%2==0)
                printf("%d\n",a[j]);
        }
        for(j=n-1; j>=0; --j){
            if(a[j]%2==1)
                printf("%d\n",a[j]);
        }
    }
    return 0;
}
