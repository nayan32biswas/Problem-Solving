#include <bits/stdc++.h>
using namespace std;
queue<int>A, B;
int main()
{
    //freopen("input.txt", "r", stdin);
    int test, a, b, x, n, m, i, num, jump, sum;
    cin>>test;
    for(int t=1; t<=test; t++){
        cin>>n>>m>>x;
        queue<int>A, B;
        for(i=0; i<n; i++){
            scanf("%d", &a);
            A.push(a);
        }
        for(i=0; i<m; i++){
            scanf("%d", &b);
            B.push(b);
        }
        jump=0, sum=0;


        while(!A.empty() && !B.empty()){
            if(A.front()>B.front()){
                num = B.front(); B.pop();
            }
            else {
                num = A.front(); A.pop();
            }
            if((sum+num)>x) break;
            else{
                sum+=num;jump++;
            }
        }
        while(!A.empty()){
            num = A.front(); A.pop();
            if((sum+num)>x) break;
            else {sum+=num;jump++;}
        }
        while(!B.empty()){
            num = B.front(); B.pop();
            if((sum+num)>x) break;
            else {sum+=num;jump++;}
        }
        cout<<jump<<endl;
    }

    return 0;
}
