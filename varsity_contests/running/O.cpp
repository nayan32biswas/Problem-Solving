#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000000
char str[SIZE];
int findStart(int len){
    int leftToSame = 0, start=0;
    char last = str[len-1];
    for(int i=len-1; i>=0; i--){
        if(str[i]==last){
            leftToSame++;
        }
        else{
            break;
        }
    }
    for(int i=0, coun=0; i<len; i++){
        if(str[i]==last){
            coun++;
            if(coun>=leftToSame){
                start = coun-leftToSame;
            }
        }
        else{
            coun = 0;
        }
    }
    return start;
}
int solve(){
    int len;
    scanf("%s", str);
    len = strlen(str);
    int start=0, end, count=0, total=0, second=0;
    for(end=len-1; start<=end && start<len; start++){
        if(str[start]==str[end]){
            end--;
            if(start>end){
                total=1;
                break;
            }
            count++;
        }
        else{
            count = 0;
            end = len-1;
        }
    }
    total += count*2;
    // cout<<total<<endl;
    return len + (len-total);
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    for(int t=1; t<=test; t++){
        printf("Case %d: %d\n", t, solve());
    }
}