#include <bits/stdc++.h>
using namespace std;
stack<int>S;
int List[55];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, type, A;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d%d", &type, &A);
        if(type==1){
            S.push(A);
            List[A]++;
        }
        else if(List[A]>0){
            int coun=1;
            while(!S.empty() && S.top() != A){
                List[S.top()]--;
                S.pop();
                coun++;
            }
            List[A]--;
            if(!S.empty()) S.pop();
            if(coun)printf("%d\n", coun);
        }
        else{
            puts("Sorry");
        }

    }
    return 0;
}

