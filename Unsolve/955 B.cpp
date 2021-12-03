#include <bits/stdc++.h>
using namespace std;
int arr[130];
int main()
{
    string str;
    cin>>str;
    int n = str.size();
    for(auto it : str){
        arr[it]++;
    }
    int one=0, odd=0;
    for(int i='a'; i<='z'; i++){
        if(arr[i]==1) one++;
        else if(arr[i]&1) odd++;
    }
    one = (one&1);
    odd = (odd&1);
    if(n&1){
        if(one==1 || odd==1){
            puts("Yes");
        }
        else puts("No");
    }
    else{
        if(!one && !odd){
            puts("Yes");
        }
        else puts("No");
    }
    return 0;
}


