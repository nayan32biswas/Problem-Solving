#include <bits/stdc++.h>
using namespace std;
bool fancy(string str){
    int arr[124];
    memset(arr, 0, sizeof(arr));
    int two=0, len=str.size();
    for(int i=0; i<len; i++){
        if(str[i]==str[i+1]){
            two++;
            if(str[i]==str[i+2]){
                return true;
            }
            if(two>=2){
                return true;
            }
        }
        else if(i<=(len-4)){
            if((str[i]==str[i+1]-1) && (str[i]==str[i+2]-2) && (str[i]==str[i+3]-3)){
                return true;
            }
        }
        arr[str[i]]++;
        if(arr[str[i]]>=5){
            return true;
        }
    }
    return false;
}
int main()
{
    int test;
    string str;
    cin>>test;
    while(test--){
        cin>>str;
        if(fancy(str)){
            puts("Fancy");
        }
        else{
            puts("Not Fancy");
        }
    }
}
