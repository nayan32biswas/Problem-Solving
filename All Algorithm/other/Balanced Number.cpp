#include <bits/stdc++.h>
using namespace std;
int arr[65];
string str;
int main()
{
    cin>>str;
    int len = str.size(), i;
    for(i=0; i<len; i++)arr[str[i]]++;
    for(i='1'; i<='9'; i++){
        if(arr[i-1]!=arr[i]) return puts("0"), 0;
    }
    cout<<arr['0']<<endl;
    return 0;
}
