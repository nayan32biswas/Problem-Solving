#include <bits/stdc++.h>
using namespace std;
deque<int>Q;
void Clear(){
    while(!Q.empty()) Q.pop_back();
}
int main()
{
    int test, x, n, m;
    string s;
    cin>>test;
    for(int t=1; t<=test; t++){
        scanf("%d%d", &n, &m);
        printf("Case %d:\n", t);
        Clear();
        while(m--){
            cin>>s;
            if(s=="pushLeft"){
                cin>>x;
                if(Q.size()==n){
                    puts("The queue is full");
                    continue;
                }
                printf("Pushed in left: %d\n", x);
                Q.push_front(x);
            }
            else if(s=="pushRight"){
                cin>>x;
                if(Q.size()==n){
                    puts("The queue is full");
                    continue;
                }
                printf("Pushed in right: %d\n", x);
                Q.push_back(x);
            }
            else if(s=="popLeft"){
                if(Q.empty()){
                    puts("The queue is empty");
                    continue;
                }
                x = Q.front();Q.pop_front();
                printf("Popped from left: %d\n", x);
            }
            else if(s=="popRight"){
                if(Q.empty()){
                    puts("The queue is empty");
                    continue;
                }
                x = Q.back();Q.pop_back();
                printf("Popped from right: %d\n", x);
            }
        }
    }
}
