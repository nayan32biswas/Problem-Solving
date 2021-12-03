#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x, Min, Max, coun;
    Max = Min = coun = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        if(x==1)
            coun++;
        else {
            Min += ((coun&1) + (coun/2));
            Max += coun;
            coun = 0;
        }
    }
    if(coun) {
        Min += ((coun&1) + (coun/2));
        Max += coun;
        coun = 0;
    }
    cout<<Min<<" "<<Max<<endl;
    return 0;
}
