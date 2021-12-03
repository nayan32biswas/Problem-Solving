#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    char a[120], x[299],R[100],F[100],C[100];
    int i,j,ln, k, l, m;
    scanf("%s",a);
    ln=strlen(a);
    for(i=0,j=0,k=0,l=0; i<ln; i++){
        if(a[i]=='R'){
            R[i]='/';
        }
        else if(a[i]=='F'){
            F[i]='+';
        }
        else if(a[i]== 'C'){
            C[i]='_';
        }
    }
    for(i=0; i<10; i++){
        if(i==0){
            for(m=0; m<10; m++)
                printf("%c",R[m]);
        }
        else if(i==1){
            for(m=0; m<10; m++)
                printf("%c",F[m]);
        }
        else if(i==2){
            for(m=0; m<10; m++)
                printf("%c",C[m]);
        }
        printf("\n");
    }
    return 0;
}
