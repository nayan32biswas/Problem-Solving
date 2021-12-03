#include <bits/stdc++.h>
using namespace std;
int n, L, a;
int number(int l, int r, double x){
    return (r-l)/x;
}
int main()
{
    int r=0, ti, li, num;
    scanf("%d%d%d", &n, &L, &a);
    int coun = 0;
    for(int i=0; i<n; i++){
        scanf("%d%d", &ti, &li);
        if(i){
            coun += number(r, ti, a);
        }
        else if(ti>0){
            coun+=number(0, ti, a);
        }
        r = ti+li;
    }
    if(r<L){
        coun += number(r, L, a);
    }
    cout<<coun<<endl;
    return 0;
}
