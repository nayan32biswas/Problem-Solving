#include<stdio.h>
#include<algorithm>
#define N 100000
using namespace std;
int main()
{
    int a[N],b[N],c[N],i,j=1,Total,temp,n;
    while(scanf("%d",&n)!=EOF&&n!=0){
        Total=0;
        for(i=0; i<n; i++)
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        for(i=0; i<n; i++){
            if(i==0||i==n-1)
                temp=b[i];

            else{
                if(temp==a[i-1])
                    temp=min(a[i],b[i]);
                else if(temp==b[i-1]){
                    temp=min(a[i],b[i]);
                    if(temp>c[i])
                        temp=c[i];
                }

                else if(temp==c[i-1])
                    temp=min(b[i],c[i]);
            }
            Total+=temp;
        }
        printf("%d. %d\n",j,Total);
        j++;
    }
    return 0;
}
