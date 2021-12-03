#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin>>n>>m;
    char str[10], c;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>c;
            if(c=='C' || c=='M' || c=='Y')
                return 0*puts("#Color");
        }
    }
    puts("#Black&White");
    return 0;
}
