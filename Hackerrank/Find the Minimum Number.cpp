#include <iostream>
#include <cstdio>
using namespace std;
string s="min(int, ";
int main()
{
    int n;
    cin>>n;
    n--;
    for(int i=0; i<n; i++) {
        cout<<s;
    }
    cout<<"int";
    for(int i=0; i<n; i++){
        cout<<')';
    }
    cout<<endl;
    return 0;
}
