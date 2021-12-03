#include <bits/stdc++.h>
using namespace std;
map<int, bool>M;
int main()
{
    int n, T;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>T;
        M[T] = !M[T];
    }
    for(auto it : M) if(it.second) return puts("Conan"), 0;
    puts("Agasa");
}
