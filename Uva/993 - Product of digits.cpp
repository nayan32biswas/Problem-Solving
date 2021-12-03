#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#define LMT 32000
using namespace std;
int main()
{
    int test, n, i, len;
    scanf("%d", &test);
    for(int t=1; t<=test; t++) {
        scanf("%d", &n);
        if(n<10){
            printf("%d\n", n);
            continue;
        }
        vector<int>V;
        for(i=9; i>1; i--)if(n%i==0){
            while(n%i==0){
                n/=i;
                V.push_back(i);
            }
        }
        if(n>9){
            puts("-1");
            continue;
        }
        reverse(V.begin(), V.end());
        len = V.size();
        for(i=0; i<len; i++){
            printf("%d", V[i]);
        }
        puts("");
    }
    return 0;
}
