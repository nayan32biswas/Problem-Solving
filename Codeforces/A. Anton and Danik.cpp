#include <iostream>
#include <cstdio>
using namespace std;
int arr[80];

int main() {
    int n;
    string s;
    cin>>n>>s;
    for(int i=0; i<n; i++) arr[s[i]]++;
    if(arr['A']==arr['D']) puts("Friendship");
    else if(arr['A']>arr['D']) puts("Anton");
    else puts("Danik");
    return 0;
}
