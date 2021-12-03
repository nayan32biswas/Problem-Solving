#include <bits/stdc++.h>
using namespace std;
#define Size 1000
int arr[Size];
int main()
{
    string s;
    int ans = 0;
    cin>>s;
    int len = s.size();
    for(int i=0; i<len; i++)if(s[i]=='Q'){
        for(int j=i+1; j<len; j++)if(s[j]=='A'){
            for(int k=j+1; k<len; k++)if(s[k]=='Q'){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
