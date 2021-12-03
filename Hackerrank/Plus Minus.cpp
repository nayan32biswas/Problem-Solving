#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("Input.txt", "r", stdin);
    int a, N;
    double zero=0, negative=0, positive=0;
    cin>>N;
    for(int i=0; i<N; i++){
        scanf("%d", &a);
        if(a==0)
            zero++;
        else if(a>0)
            positive++;
        else
            negative++;
    }
    printf("%.6lf\n%.6lf\n%.6lf", positive/N, negative/N, zero/N);
    return 0;
}
