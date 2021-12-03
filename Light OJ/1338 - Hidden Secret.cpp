#include<bits/stdc++.h>
using namespace std;
int  xar[130], xarr[130];
int main()
{
    //freopen("input.txt", "r", stdin);
    char ar[130],arr[130];
    int len1,len2,i,j,t,test,toplen;
    bool b=1;
    scanf("%d",&test);
    getchar();
    for(t=1;t<=test;t++)
    {
        memset(xar,0,sizeof(xar));
        memset(xarr,0,sizeof(xarr));
        gets(ar);
        gets(arr);

        len1=strlen(ar);
        len2=strlen(arr);
        if(len1<len2)
            toplen=len2;

        else
            toplen=len1;

        for(i=0; i<toplen; i++){
            if(i<len1){
                if(ar[i]<95)
                    ar[i]=ar[i]+32;
                xar[ar[i]]++;
            }
            if(i<len2){
                if(arr[i]<95)
                    arr[i]=arr[i]+32;

                xarr[arr[i]]++;
            }
        }
        b=1;

        for(i=97; i<123; i++){
            if( xar[i]!=xarr[i]){
                b=0;
                break;
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
