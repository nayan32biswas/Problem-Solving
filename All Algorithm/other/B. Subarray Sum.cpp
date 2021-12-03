#include <bits/stdc++.h>
using namespace std;
template <typename T>
void read(T &x)
{
    char c;
    bool t=false;
    for(c=getchar(); (c<'0'||c>'9') && c!='-'; c=getchar());
    if(c=='-'){c=getchar(); t=true;}
    for(x=c-'0', c=getchar(); c>='0'&&c<='9'; x=x*10+c-'0', c=getchar());
    if(t) x=-1;
}

#define ppi pair<int, int>
vector< ppi > arr;
int N;
bool ck;
int subsum(int i, int K){
    int sum=0;
    for(; i<N && K>=0; ){
        sum+=arr[i++].first;
        K-=arr[i].second;
    }
    if(i==N) ck=true;
    return sum;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int i, j, test, neg, temp, K, ans;
    cin>>test;
    for(int t=1; t<=test; t++){
        arr.clear();

        scanf("%d%d", &N, &K);
        for(i=0, neg=0; i<N; i++){
            read(temp);
            cout<<temp<<' ';
            if(temp<0) neg++;
            else if(temp>0){
                arr.push_back(make_pair(temp, neg));
                neg=0;
            }
        }
        cout<<endl;
        N = arr.size();
        for(i=0; i<N; i++) printf("%d %d\n", arr[i].first, arr[i].second);
        ck = false;
        for(i=0, ans=0; i<N && ck==false; i++){
            temp = subsum(i, K);
            ans = max(ans, temp);
        }
        printf("Case %d: %d\n", t, ans);
    }
    return 0;
}
