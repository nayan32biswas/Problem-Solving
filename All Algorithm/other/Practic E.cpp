#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s[150];
    int len1, len2, n, test, a, b, c, arr[150];
    int Max, Min, posi, posj;
    bool ck;
    cin>>test;
    for(int t=1; t<=test; t++){
        cin>>n;
        memset(arr,0,sizeof(arr));
        Max=0, Min=INT_MAX;
        for(int i=0; i<n; i++){
            cin>>s[i]>>a>>b>>c;
            arr[i]=(a*b*c);
            if(Max<arr[i]){
                posi = i;
                Max = arr[i];
            }
            if(Min>arr[i]){
                posj = i;
                Min = arr[i];
            }
        }
        printf("Case %d: ", t);
        if(Max==Min)cout<<"no thief\n";
        else
            cout<<s[posi]<<" took chocolate from "<<s[posj]<<endl;
    }

    return 0;
}
