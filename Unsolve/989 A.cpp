#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    bool A, B, C;
    cin>>str;
    A = B = C = false;
    for(auto it : str){
        if(it=='.'){
            A = B = C = false;
        }
        if(it=='A') A = true;
        if(it=='B') B = true;
        if(it=='C') C = true;
        if(A && B && C)return puts("Yes");
    }
    puts("No");
    return 0;
}
