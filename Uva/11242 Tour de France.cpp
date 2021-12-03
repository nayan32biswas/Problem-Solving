#include <bits/stdc++.h>
using namespace std;
#define fix(n) fixed<<setprecision(n)
vector<double>vec;
int main()
{
    int f, r;
    int fff[10], rrr[10];
    double ans;
    while(scanf("%d", &f) && f){
        scanf("%d", &r);
        vec.clear();
        for(int i=0; i<f; i++)scanf("%d", &fff[i]);
        for(int i=0; i<r; i++)scanf("%d", &rrr[i]);
        for(int i=0; i<f; i++){
            for(int j=0; j<r; j++){
                vec.push_back(double(fff[i])/rrr[j]);
            }
        }
        sort(vec.begin(), vec.end());
        ans = 0;
        for(int len = vec.size()-1, i=0; i<len; i++){
            ans = max(ans, vec[i+1]/vec[i]);
        }
        cout<<fix(2)<<ans<<endl;
    }
    return 0;
}
