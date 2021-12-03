#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    int arr[60], j=0;
    cin>>s;
    int len=s.size();
    for(int i=0; i<len; i++){
        if(s[i]=='1' || s[i]=='2' || s[i]=='3')
            arr[j++]=(s[i]-48);
    }
    sort(arr, arr+j);
    for(int i=0; i<j; i++){
        if(i!=0) cout<<'+';
        cout<<arr[i];
    }
    cout<<endl;
    return 0;
}
