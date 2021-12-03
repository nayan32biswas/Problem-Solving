#include<bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n,a,b,c=1,mult;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&a,&b);
        printf("Case %d: ", c++);
        if(a>b) swap(a, b);
        if(a==1)printf("%d\n", b);
        else if(a==2 && b>=2){
            mult = b/8;
            mult *= 8;
            a = b%8;
            if(a==1) a=2;
            else if(a>1 && a<5) a=4;
            else if(a==5) a=6;
            else if(a>5 && a<9) a=8;
            printf("%d\n", mult+a);
        }
        else{
            mult= (((b+1)>>1)*((a+1)>>1)) + ((a>>1)*(b>>1));
            printf("%d\n",mult);
        }
    }
    return 0;
}
