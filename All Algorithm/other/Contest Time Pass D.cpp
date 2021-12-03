#include<stdio.h>
int main()
{
    unsigned long long int a[1000],b[1000],c[1000],n;
    int i,j,x,m;
    while(scanf("%lld",&n)!=EOF&&n!=0){
        j=1;
        for(i=0; i<n; i++)
            scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
        x=0;
        for(i=0; i<n; i++){
            if(i==0) m=b[i];
            else if(i==n-1) m=b[i];
            else{
                if(m==a[i-1]){
                    if(a[i]<b[i])
                        m=a[i];
                    else
                        m=b[i];
                }
                else if(m==b[i-1]){
                    if(a[i]<b[i]&&a[i]<c[i])
                        m=a[i];
                    else if(b[i]<a[i]&&b[i]<c[i])
                        m=b[i];
                    else m=c[i];
                }
                else if(m==c[i-1]){
                    if(b[i]<c[i])
                        m=b[i];
                    else m=c[i];
                }
            }
            x=x+m;
        }
        printf("%d. %d\n",j,x);
        j++;
    }
    return 0;
}
