#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int test, n;
    cin>>test;
    for(int t=1; t<=test; t++){
        cin>>n;
        printf("Case %d:\n", t);
        for(int i=1; i<=10; i++){
            printf("%d X %d = %d\n", n, i, (n*i));
        }
    }
    return 0;
}
