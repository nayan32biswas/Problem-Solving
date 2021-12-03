#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char ch[200050];
    int test,c1=0, c2=0,ans;
    scanf("%d",&test);
    getchar();
    for(int i=0; i<test; i++){
        scanf("%c",&ch[i]);
        if(ch[i]!= '<' && ch[i]!='>')test++;
    }
    for(int i=0; i<test; i++){
        if(ch[i] == '<') c1++;
        else if(ch[i] == '>') c2++;
    }
    ans=abs(c1-c2);
    printf("%d\n",ans);
    return 0;
}
