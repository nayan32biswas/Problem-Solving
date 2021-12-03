#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    //freopen("Input.txt", "r", stdin);
    int len;
    char s1[2020];
    string s;
    cin>>len>>s;
    if(len&1){
        int mid=len>>1;
        s1[mid]=s[0];
        for(int i=1, j=1; i<=len/2; i++){
            s1[mid-i]=s[j++];
            s1[mid+i]=s[j++];
        }
        for(int i=0; i<len; i++) printf("%c", s1[i]);
        cout<<endl;
    }
    else{
        int mid=len>>1;
        mid--;
        s1[mid]=s[0];
        s1[mid+1]=s[1];
        for(int i=1, j=2; i<len>>1; i++){
            s1[mid-i]=s[j++];
            s1[mid+i+1]=s[j++];
        }
        for(int i=0; i<len; i++) printf("%c", s1[i]);
        cout<<endl;
    }
    return 0;
}
