#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
    string s[105],x;
    char c;
    int test,N,arr[150],Max=0,len,i,k,l,condition=0;
    scanf("%d",&test);
    scanf("%d",&N);
    getchar();
    for(int t=0; t<test; t++){
        cin>>s[t];

    }
    for(i=0; i<N; i++){
        scanf("%d",&arr[i]);
        len = s[arr[i]].length();
        if(len>Max)
            Max=len;
    }
    for(i=0,k=0; i<Max; i++){
        for(int j=0; j<N; j++){
            if(j==0) c = s[j][i];
            if(c==s[arr[j]-1][i]){
                if(j==N-1){
                        x[k]=s[arr[j]-1][i];
                        condition++;
                }
            }
            if(c != s[arr[j]-1][i]){
                x[k]='?';
                break;
            }
        }
        k++;
    }
    if(condition>0){
        printf("Yes\n");
        for(int i=0; i<Max; i++)
            printf("%c",x[i]);
        printf("\n");
    }
    else printf("No\n");
    return 0;
}
