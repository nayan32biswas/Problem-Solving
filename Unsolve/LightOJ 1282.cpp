#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
string addition(string &value1, string &value2);
string multiply(string &value1, string &value2);
string power(string &x, string &y);
bool odd(string &str);
// string solve(string &a, string &b)
// {

//     // cout << a << " " << b << endl;
//     return power(a, b);
// }

long long firstkdigits(lli n, lli p, lli k)
{
    long double product = n * log10(n);
    long double decimal_part = product - floor(product);
    decimal_part = pow(10, decimal_part);
    long long digits = pow(10, k - 1), i = 0;
    return decimal_part * digits;
}

void solve(lli a, lli b)
{
    cout << firstkdigits(a, b, 3) << endl;
}
int main()
{
    freopen("input.txt", "r", stdin);
    int test;
    lli a, b;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        scanf("%lld%lld", &a, &b);
        cout << "Case " << t << ": ";
        solve(a, b);
    }
}

string addition(string &value1, string &value2)
{
    string x;
    int len, top_len, sum = 0;
    top_len = value1.size();
    len = value2.size();
    if (top_len < len)
    {
        swap(value1, value2);
        swap(len, top_len);
    }
    for (int i = top_len - 1, k = len - 1; i >= 0; i--, k--)
    {
        if (k < 0)
            sum += (value1[i] - 48);
        else
            sum += ((value1[i] - 48) + (value2[k] - 48));
        x += (sum % 10) + 48;
        sum /= 10;
    }
    if (sum > 0)
        x += (sum + 48);
    reverse(x.begin(), x.end());
    return x;
}
string multiply(string &value1, string &value2)
{
    string temp = "";
    vector<string> sum;
    reverse(value1.begin(), value1.end());
    reverse(value2.begin(), value2.end());
    while (value1.back() == '0')
        value1.pop_back();
    while (value2.back() == '0')
        value2.pop_back();
    if (value1.size() == 0 || value2.size() == 0)
        return "0";
    int space = 0;
    for (auto val1 : value1)
    {
        sum.push_back(temp);
        int mult = space;
        while (mult--)
            sum.back() += "0";
        val1 -= '0';
        mult = 0;
        for (auto it : value2)
        {
            it -= '0';
            mult += (val1 * it);
            sum.back() += ((mult % 10) + '0');
            mult /= 10;
        }
        if (mult > 0)
        {
            sum.back() += ((mult % 10) + '0');
        }
        reverse(sum.back().begin(), sum.back().end());
        space++;
    }
    string ans = "";
    for (auto it : sum)
        ans = addition(it, ans);
    return ans;
}
bool odd(string &str)
{
    int ch = str[str.size() - 1] - '0';
    return ch & 1;
}
string div_by_two(string str)
{
    string ans;
    int pos = 0;
    int num = str[pos] - '0';
    while (num < 2)
        num = num * 10 + (str[++pos] - '0');
    while (str.size() > pos)
    {
        ans += (num / 2) + '0';
        num = (num % 2) * 10 + str[++pos] - '0';
    }
    if (ans.size() == 0)
        return "0";
    return ans;
}
string power(string &x, string &y)
{
    string temp;
    if (y.size() == 1 && y[0] == '0')
        return "1";
    if (y.size() == 1 && y[0] == '1')
        return x;
    temp = div_by_two(y);
    // cout<<temp<<endl;
    temp = power(x, temp);
    // cout << y[y.size() - 1] << " " << odd(y) << endl;
    if (odd(y))
    {
        return multiply(temp, temp);
    }
    else
    {
        string aaa = multiply(x, temp);
        return multiply(aaa, temp);
    }
}