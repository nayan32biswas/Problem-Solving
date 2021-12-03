#include <cstdio>
#include <stack>
#include <time.h>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    int t, i;
    char str[1000];
    scanf("%d\n",&t);
    while(t--){
        scanf("%s", str);
        stack<char> stk;
        for(i=0; str[i]; i++){
            if(!stk.empty() && str[i]==')' && stk.top()=='(')
                stk.pop();
            else if(!stk.empty() && str[i]==']' && stk.top()=='[')
                stk.pop();
            else stk.push(str[i]);
        }
        if(stk.empty()) puts("Yes");
        else puts("No");
    }
    printf("%d\n", clock());
    return 0;
}
