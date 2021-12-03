#include <stdio.h>
#include <iostream>
using namespace std;
double arr[100009], temp[100008];
int main()
{
    //freopen("input.txt", "r", stdin);
    int N, Q, I, i;
    double s, sum=0;
    scanf("%d%d", &N, &Q);
    for(i=0; i<N; i++) scanf("%lf", &arr[i]);
    while(Q--){
        scanf("%d", &I);
        if(I==0){
            scanf("%d%lf", &I, &s);
            I--;
            arr[I]+=s;
            s = s/(N-1);
            temp[I]+=s;
            sum+=s;
        }
        else{
            scanf("%d", &I);
            I--;
            printf("%.7lf\n", (arr[I]-sum)+temp[I]);
        }
    }
    return 0;
}
