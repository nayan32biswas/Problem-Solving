#include <bits/stdc++.h>
using namespace std;
bool solve()
{
    string str;
    long long num = 0, b;
    cin >> str >> b;
    int i = 0;
    if (str[i] == '-')
        i++;
    if (b < 0)
        b = -b;
    
    for (; str[i]; i++)
    {
        num = num*10 + (str[i] - 48);
        // cout<<num<<", ";
        if(num>=b){
            num %= b;
        }
    }
    return num == 0;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        printf("Case %d: ", t);
        puts(solve() ? "divisible" : "not divisible");
    }
    return 0;
}