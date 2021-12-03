#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
    string s[105],x;
    char c;
    int test,N,arr[150], Max=0, Min=150,len,i,k,l;
    int j,condition=0;
    scanf("%d",&test);
    scanf("%d",&N);
    getchar();
    for(int t=0; t<test; t++){
        cin>>s[t];
    }
    for(i=0; i<N; i++){
        scanf("%d",&arr[i]);
        len = s[arr[i]].size();
        if(Max<len) Max = len;
        if(Min>len) Min = len;
    }
    sort(arr,arr+N);
    for(i=0,k=0; i<Min; i++){
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
        for(int i=0; i<Min; i++)
            printf("%c",x[i]);
        for(j=i; j<Max; j++)
            printf("?");
        printf("\n");
    }
    else printf("No\n");
    return 0;
}
