#include <bits/stdc++.h>
using namespace std;
int arr[30];
bool is(int n){
    for(int i=0; i<20; i++) if(arr[i]==n) return true;
    return false;
}
int main()
{
    int a=0, b=1, c;
    for(int i=0; i<20; i++){
        c = a+b;
        a = b;
        b = c;
        arr[i] = b-1;
    }
    //for(int i=0; i<20; i++) cout<<arr[i]<<endl;
    cin>>a;
    for(int i=0; i<a; i++) {
        if(is(i)) printf("O");
        else printf("o");
    }
    puts("");
    return 0;
}
