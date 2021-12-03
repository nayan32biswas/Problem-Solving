#include <cstdio>
#include <iostream>
#include <cmath>
#define ull unsigned long long
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, i;
    ull num;
    while(scanf("%d", &n)==1 && n) {
        if(n==2 || n==3 || n==5 || n==7 || n==13 || n==17 || n==19 || n==31){
            num = pow(2, n-1)*(pow(2, n)-1);
            printf("Perfect: %llu!\n", num);
        }
        else if(n==11 || n==23 || n==29){
            puts("Given number is prime. But, NO perfect number is available.");
        }
        else
            puts("Given number is NOT prime! NO perfect number is available.");
    }
    return 0;
}
