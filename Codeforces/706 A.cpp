#include <bits/stdc++.h>
using namespace std;
int main()
{
    double a, b, n, x, y, Min, temp, v;
    cin>>a>>b>>n;
    Min = 999999;
    for(int i=0; i<n; i++) {
        cin>>x>>y>>v;
        temp = sqrt(((a-x)*(a-x))+((b-y)*(b-y)));
        temp/=v;
        if(temp<Min){
            Min = temp;
        }
    }
    printf("%.12lf\n", Min);
    return 0;
}
