#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    int n, m, i, temp=0;
    int arr;
    cin>>n;
    for(i=0, m=0; i<n; i++) {
        cin>>arr;
        if(temp==0){
            temp = arr;
            m++;
        }
        else temp--;
    }
    cout<<m<<endl;
}
