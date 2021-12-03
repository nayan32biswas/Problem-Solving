#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int arr[109][109], n, sum;
    bool b = true;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++)
            cin>>arr[i][j];
    }

    for(int i=0; i<3; i++){
        sum=0;
        for(int j=0; j<n; j++)
            sum+=arr[j][i];

        if(sum!=0){b=false; break;}
    }
    if(b==true) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
