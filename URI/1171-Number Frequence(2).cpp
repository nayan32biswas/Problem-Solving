#include <stdio.h>
#define N 2020
int main()
{
    int n,i,b,j,a[N]={0};
    scanf("%d",&n);
    for (i=0; i<n; i++){
        scanf("%d",&b);
        a[b]++;
    }
    for (j=0; j<N; j++)
        if (a[j] > 0)
            printf("%d aparece %d vez(es)\n",j,a[j]);
    return 0;
}
/*#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
    int a[2000];
    int n,x,i,j;
    scanf("%d",&n);
    for(i=0; i<n; i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    x=1;
    for(i=0; i<n; i++){
        if(a[i]==a[i+1]){
            x++;
            continue;
        }
        printf("%d aparece %d vez(es)\n",a[i],x);
        x=1;
    }
    return 0;
}*/
