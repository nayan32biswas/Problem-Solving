#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1, s2;
    int len1, len2, test, ar[130], arr[130], Maxlen;
    bool b;
    cin>>test;
    getchar();
    for(int t=1; t<=test; t++){
        getline(cin,s1);
        getline(cin,s2);
        len1 = s1.size();
        len2 = s2.size();
        memset(ar, 0, sizeof(ar));
        memset(arr, 0, sizeof(arr));
        Maxlen = max(len1, len2);
        for(int i=0; i<Maxlen; i++){
            if(i<len1){
                if(s1[i]<95)
                    s1[i]+=32;

                ar[s1[i]]++;
            }
            if(i<len2){
                if(s2[i]<95)
                    s2[i]+=32;
                arr[s2[i]]++;
            }
        }
        b = true;
        for(int i=97; i<123; i++){
            if(ar[i]!=arr[i]){
                b=false;
                break;
            }
        }
        printf("Case %d: ", t);
        printf(b==true ? "Yes\n" : "No\n");
    }
    return 0;
}
