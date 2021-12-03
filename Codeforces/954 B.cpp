#include <bits/stdc++.h>
using namespace std;
int n, Max;
string str;
bool Find(int x){
    int i, j;
    for(j=0, i=x; i<n && j<x; j++, i++){
        if(str[i]!=str[j]) return false;
    }
    if(j<x) return false;
    return true;
}
int main()
{
    cin>>n>>str;
    for(int i=n/2+1; i>1; i--){
        if(Find(i)){
            cout<<n-i+1<<endl;
            return 0;
        }
    }
    cout<<n<<endl;
    return 0;
}
