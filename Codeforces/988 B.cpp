#include <bits/stdc++.h>
using namespace std;
#define Size 105
string arr[Size];
int KMP(string test, string pattern) {
    int i, j, len, len1;
    len = pattern.size();
    len1 = test.size();
    if(len>len1) return -1;
    int temp[len];
    for(i=1, j=0, temp[0]=0; i<len; ){
        // if index i and index j is same then increment i & j;
        if(pattern[i]==pattern[j]){temp[i++] = ++j;}
        // if j is in index 0 then forward i;
        else if(j==0) temp[i++]=0;
        // if index i and index j is not same then decrement j;
        else j=temp[j-1];
    }
    for(i=0, j=0; i<len1 && j<len; ) {
        if(pattern[j]==test[i]){i++, j++;} // flow past loop commend;
        else if(j==0) i++;
        else j=temp[j-1];
    }
    if(j==len) return i-len;
    return -1;
}
bool cmp(string a, string b){
    int A = a.size();
    int B = b.size();
    if(A!=B){
        return A<B;
    }
    return a<b;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)cin>>arr[i];
    sort(arr, arr+n, cmp);
    for(int i=0; i<n-1; i++){
        if(KMP(arr[i+1], arr[i])==-1){
            return puts("NO"), 0;
        }
    }
    puts("YES");
    for(int i=0; i<n; i++)cout<<arr[i]<<endl;
    return 0;
}

/*
5
a
abacaba
ba
aba
abac
*/
