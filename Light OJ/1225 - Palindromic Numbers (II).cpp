#include<stdio.h>
#include<string.h>
int main()
{
    char ar[20];
    int  len,i,j, test, t;
    bool b=1;
    scanf("%d", &test);
    getchar();
    for(t=1; t<=test; t++){
        scanf("%s",ar);
        len= strlen(ar);
        b=1;
        for(i=0,j=len-1;i<=len/2;i++,j--)
        {
            if(i<j)
            {
                if(ar[i]!= ar[j])
                {
                    b=0;
                    break;
                }
            }
        }
        printf("Case %d: ",t);
        if(b==0)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
