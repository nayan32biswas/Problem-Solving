#include <bits/stdc++.h>
#define N 100100
using namespace std;
int main()
{
    int test, save1[N], save2[N], temp, sum, n, sum1, sum2, x, y;
    cin>>test;
    int a1, a2, a3, a4;
    for(int t=1; t<=test; t++){
        cin>> x >> y;
        sum = 0;
        save1[0] = save2[0] = 0;
        for(int i=1; i<=x; i++){
            cin>>temp;
            sum+=temp;
            save1[i]=sum;
        }
        sum = 0;
        for(int i=1; i<=y; i++){
            cin>>temp;
            sum+=temp;
            save2[i]=sum;
        }
        cin>>n;
        cout<<"Case "<<t<<":"<<endl;
        for(int j=0; j<x; j++){
            cin>> a1 >> a2 >> a3 >> a4;
            sum1 = save1[a2] - save1[a1-1];
            sum2 = save2[a4] - save2[a3-1];
            cout<<sum1*sum2<<endl;
        }
    }
    return 0;
}
