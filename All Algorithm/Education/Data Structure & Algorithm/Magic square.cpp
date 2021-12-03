#include <bits/stdc++.h>
using namespace std;
int arr[1000][1000], N;
int main()
{
    freopen("input.txt", "r", stdin);
    cin>>N;
    int coun=0, sumd=0, sumdd=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++)
            cin>>arr[i][j];
    }
    for(int i=0; i<N; i++) sumd+=arr[i][i];
    for(int i=0, j=N-1; i<N; i++, j--) sumdd+=arr[i][j];
    if(sumd!=sumdd)return puts("NO"), 0;

    for(int i=0; i<N; i++){
        int sumrow=0, sumclm=0;
        for(int j=0; j<N; j++) sumrow+=arr[i][j];
        for(int j=0; j<N; j++) sumclm+=arr[j][i];
        if(sumd!=sumrow)return puts("NO"), 0;
        if(sumd!=sumclm)return puts("NO"), 0;
    }
    puts("YES");

    return 0;
}
