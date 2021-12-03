#include <bits/stdc++.h>
using namespace std;
#define Size 200001
int main()
{
    string str;
    cin>>str;
    int len = str.size();
    if(str[0]=='1' || str[len-1]=='1'){
        return puts("-1"), 0;
    }
    vector<int>Array, Array1;
    Array.push_back(1);
    for(int i=2; i<len; i++){
        if(str[i-1]=='1'){
            Array.push_back(i);
        }
        else{
            Array1.push_back(i);
        }
    }
    Array.push_back(len);
    if(Array1.size()==0){
        return puts("-1"), 0;
    }
    puts("2");
    printf("%d", Array.size());
    for(auto it : Array) printf(" %d", it);
    puts("");

    printf("%d", Array1.size());
    for(auto it : Array1) printf(" %d", it);
    puts("");
    return 0;
}
