#include <bits/stdc++.h>
using namespace std;
struct data{
    long long num=0, win=0;
}one, two;
deque<data>Q;
int n;
long long k;
void push(data &a, data &b){
    a.win++;
    Q.push_front(a);
    Q.push_back(b);
}
void solve(){
    for(int i=0; i<n; i++){
        cin>>one.num;
        one.win = 0;
        Q.push_back(one);
    }
    while(true){
        one = Q.front(); Q.pop_front();
        two = Q.front(); Q.pop_front();
        if(one.num==two.num){
            if(one.win<two.win)push(two, one);
            else push(one, two);
        }
        else if(one.num<two.num) push(two, one);
        else push(one, two);
        if(Q.front().win==k){
            cout<<Q.front().num<<endl;
            return;
        }
    }
}
int main()
{

    cin>>n>>k;
    if(k<=500) solve();
    else {
        long long Max = -(1e15);
        int x;
        for(int i=0; i<n; i++){
            cin>>x;
            Max = max((long long)x, Max);
        }
        cout<<Max<<endl;
    }
}

