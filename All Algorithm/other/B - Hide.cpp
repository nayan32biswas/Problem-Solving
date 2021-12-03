#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int arr[100], arr1[100], test, len, len1, i;
    string s, s1;
    cin>>test;
    getchar();
    for(int t=1; t<=test; t++){
        memset(arr, 0, sizeof(arr));
        memset(arr1, 0, sizeof(arr1));
        getline(cin, s);
        getline(cin, s1);
        len = s.size();
        len1 = s1.size();
        for(i=0; i<len; i++){
            if(s[i]>90) arr[s[i]-32]++;
            else arr[s[i]]++;
        }
        for(i=0; i<len1; i++){
            if(s1[i]>90) arr1[s1[i]-32]++;
            else arr1[s1[i]]++;
        }
        printf("Case %d: ", t);
        for(i=65; i<91; i++)if(arr[i]>arr1[i]){
            puts("No");
            break;
        }
        if(i==91) puts("Yes");
    }
}
