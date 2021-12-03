#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n, temp, ans=0, cou;
    cin>>n;
    for(int i=0; i<n; i++){
        cou=0;
        for(int j=0; j<3; j++){
            scanf("%d", &temp);
            if(temp==1)
                cou++;
        }
        if(cou>=2) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
