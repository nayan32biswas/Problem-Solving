#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    long long A, S, K, X, Y;
    cin>>A>>S>>K>>X>>Y;
    int start = 0, End = K, mid;
    long long changeA, changeS;
    while(start<=End){
        mid = (start+End)>>1;
        changeA = A+(X*mid);
        changeS = S+(Y*(K-mid));
        if(changeA==changeS){
            cout<<mid<<endl;
            return 0;
        }
        else if(changeA<changeS){
            start = mid+1;
        }
        else {
            End = mid-1;
        }
    }
    puts("-1");
    return 0;
}
