#include<stdio.h>
int main()
{
    long long int n, k, i, j, x;
    while(scanf("%lld%lld",&n,&k)!=EOF){
        if(n%2 == 0){
            if(k <= n/2 ){
                for(i=1,j=1; i<=n; i+=2,j++)
                    if(j == k){
                        printf("%lld\n",i);
                        break;
                    }
            }
            else if(k > n/2){
                for(i=2,j=(n/2)+1; i<=n; i+=2,j++)
                    if(j == k){
                        printf("%lld\n",i);
                        break;
                    }
            }
        }
        else if(n%2 == 1){
            if(k+1 <= n/2 ){
                for(i=1,j=1; i<=n; i+=2,j++)
                    if(j == k){
                        printf("%lld\n",i);
                        break;
                    }
            }
            else if(k > (n/2)+1){
                for(i=2,j=(n/2)+2; i<=n; i+=2,j++)
                    if(j == k){
                        printf("%lld\n",i);
                        break;
                    }
            }
        }
    }
    return 0;
}

