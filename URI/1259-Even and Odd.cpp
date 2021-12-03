#include<stdio.h>
#define x 100000
int main()
{
    int n,a,odd[x],even[x];
    int i,j,o=0,e=0,temp;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf("%d",&a);
        if(a%2==0){
            even[e]=a;
            e++;
        }
        else if(a%2==1){
            odd[o]=a;
            o++;
        }
    }
    for(i=0; i<e; i++){
        for(j=i+1; j<e; j++){
            if(even[i]>even[j]){
                temp=even[i];
                even[i]=even[j];
                even[j]=temp;
            }
        }
        printf("%d\n",even[i]);
    }
    temp=0;
    for(i=0; i<o; i++){
        for(j=i+1; j<o; j++){
            if(odd[i]<odd[j]){
                temp=odd[i];
                odd[i]=odd[j];
                odd[j]=temp;
            }
        }
        printf("%d\n",odd[i]);
    }
    return 0;
}
