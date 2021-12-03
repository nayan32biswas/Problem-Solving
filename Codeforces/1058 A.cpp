#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>x;
        if(x){
            puts("HARD");
            return 0;
        }
    }
    puts("EASY");

    return 0;
}
