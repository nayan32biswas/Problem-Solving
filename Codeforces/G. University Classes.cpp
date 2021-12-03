#include <bits/stdc++.h>
using namespace std;
int arr[10];
int main()
{
    int n;
    cin>>n;
    string s;
    while(n--){
        cin>>s;
        for(int i=0; i<7; i++)if(s[i]=='1'){
            arr[i]++;
        }
    }
    sort(arr, arr+7);
    cout<<arr[6]<<endl;
    return 0;
}
