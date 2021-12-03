#include<stdio.h>
int main()
{
    long long int a,b[1000],i,j,temp,ch=0;
    for(i=0; i<1000; i++){
        scanf("%lld",&a);
        if(a<0){
            continue;
            ch++;
        }
        if(a==0){
                break;
                ch++;
        }
        else{
            b[i]=a;
            ch++;
        }
    }

    for(i=0; i<ch; i++){
        for(j=i+1; j<ch; j++){
            if(b[i]<b[j]){
                temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
        printf("%lld %lld\n",b[1],b[0]);

    return 0;
}
