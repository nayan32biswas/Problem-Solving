#include <iostream>
#include <cstdio>
using namespace std;
int arr1[130], arr2[130];
int main()
{
    string a, b, x;
    cin>>a>>b>>x;
    int len1, len2, lenx;
    len1=a.size();
    len2=b.size();
    lenx=x.size();
    for(int i=0; i<lenx; i++){
        if(i<len1){
            arr1[a[i]]++;
        }
        if(i<len2){
            arr1[b[i]]++;
        }
        arr2[x[i]]++;
    }
    bool ck=true;
    for(int i=65; i<=90; i++){
        if(arr1[i]!=arr2[i]){
            ck=false;
            break;
        }
    }
    if(ck==true)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}
