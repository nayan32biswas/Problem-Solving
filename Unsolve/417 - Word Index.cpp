#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int finde(char s[]) {
    int i, J, len, ans;
    len = strlen(s);
    ans = s[len-1]-96;
    cout<<ans<<endl;
    for(i=len-2, J=1; i>=0; i--, J++) {
        if(s[i-1]>s[i]) return 0;
        cout<<(double)((s[i]-96)*pow(26, J))<<endl;
        ans = ans + ((s[i]-96)*pow(26, J));
        if(ans>83681) ans%=83681;
    }
    return ans;
}
int main()
{
    //freopen("Input.txt", "r", stdin);
    char str[1000];
    int len, i, po;
    long long ans;
    bool ck;
    while(scanf("%s", str)!=EOF){
        printf("%d\n\n\n", finde(str));
    }

    return 0;
}
