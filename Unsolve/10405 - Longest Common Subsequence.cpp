#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int arr[130], arr1[130];
string s, s1;
int main()
{
    // freopen("input.txt", "r", stdin);
    int len, len1, i, ans;
    while(cin>>s>>s1){
        len = s.size();
        len1 = s1.size();
        memset(arr, 0, sizeof(arr));
        memset(arr1, 0, sizeof(arr1));
        ans = 0;
        for(i=0; s[i]; arr[s[i]]++, i++);
        for(i=0; s1[i]; arr1[s1[i]]++, i++);
        for(i=47; i<125; i++){
            ans+=min(arr[i], arr1[i]);
            if(arr[i]>0 && arr1[i]>0){
                cout<<arr[i]<<' '<<arr1[i]<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
