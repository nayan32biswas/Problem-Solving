#include <bits/stdc++.h>
using namespace std;

int main()
{
    int Max=1, i, n, past, x, temp;
    scanf("%d", &n);
    scanf("%d", &past);
    for(i=1, temp=1; i<n; i++){
        scanf("%d", &x);
        if(x<past){
            Max = max(Max, temp);
            temp = 0;
        }
        temp++;
        past=x;
    }
    cout<<max(temp, Max)<<endl;
    return 0;
}
