#include <bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("input.txt", "r", stdin);
    int test, l1, r1, l2, r2;
    cin>>test;
    while(test--)
    {
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        if(l1!=l2){
            printf("%d %d\n", l1, l2);
        }
        else if(l1!=r2){
            printf("%d %d\n", l1, r2);
        }
        else if(r1!=l1){
            printf("%d %d\n", r1, l1);
        }
        else if(r1!=r2){
            printf("%d %d\n", l1, r2);
        }
    }
    return 0;
}