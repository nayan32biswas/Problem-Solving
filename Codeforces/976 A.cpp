#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    int n;
    cin>>n>>str;
    if(n==1){
        cout<<str<<endl;
        return 0;
    }
    cout<<"1";
    for(auto it : str){
        if(it=='0'){
            printf("0");
        }
    }
    puts("");
    return 0;

}
