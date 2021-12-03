#include<stdio.h>
#include<math.h>
#define N 10000
int main()
{
    long long int a,b,array[N],array1[N],array2[N];
    int i,n,l,x,mult;
    while(scanf("%lld%lld",&a,&b)!=EOF){
        i=0;
        while(a!=0||b!=0){
            n=a%2;
            a=a/2;
            array[i]=n;
            x=b%2;
            b=b/2;
            array1[i]=x;
            i++;
        }
        mult=0;
        for(l=0; l<i; l++){
            if(array[l]==array1[l])
                array2[l]=0;
            else if(array[l]==1||array1[l]==1)
                array2[l]=1;
            if(array2[l]==1)
                mult+=pow(2,l);
        }
        printf("%lld\n",mult);
    }
    return 0;
}
