#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int a, b, Max, Min, ans1=0, ans2=0;
    cin>>a;
    cin>>b;
    Min = b, Max=b;
    for(int i=1; i<a; i++){
        scanf("%d", &b);
        if(b>Max){
            Max = b;
            ans1++;
            //printf("Max   %d\n", b);
        }
        if(b<Min){
            Min=b;
            ans2++;
            //printf("Min   %d\n", b);
        }
    }
    cout<<ans1<<' '<<ans2<<endl;
    return 0;
}
