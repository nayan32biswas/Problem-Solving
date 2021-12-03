#include <bits/stdc++.h>
using namespace std;
int n;
string str, ans;
int togol(string &temp, int post)
{
    return (str[post] != temp[0]) + (str[post + 1] != temp[1]) + (str[post + 2] != temp[2]);
}
int for_each(string temp)
{
    int coun = 0;
    ans = "";
    for (int i = 0; i < n - 2; i += 3)
    {
        coun += togol(temp, i);
        ans += temp;
    }
    int x = n % 3;
    if (x == 2)
    {
        coun += str[n - 2] != temp[0];
        coun += str[n - 1] != temp[1];
        ans += temp[0], ans += temp[1];
    }
    else if (x == 1)
    {
        coun += str[n - 1] != temp[0];
        ans += temp[0];
    }
    return coun;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    string final_ans;
    cin >> n >> str;
    if (n == 2 && str[0] != str[1])
    {
        printf("0\n");
        cout << str << endl;
        return 0;
    }
    string arr[] = {"RGB", "RBG", "GRB", "GBR", "BRG", "BGR"};
    int Min = 1000000, x;
    for (auto it : arr)
    {
        int coun = 0;
        x = for_each(it);
        if (x < Min)
        {
            Min = x;
            final_ans = ans;
        }
    }
    cout << Min << endl;
    cout << final_ans << endl;
    return 0;
}