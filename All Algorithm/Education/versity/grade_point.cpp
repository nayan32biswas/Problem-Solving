#include <bits/stdc++.h>
using namespace std;
map<string, pair<double, double>> result;
double max(double a, double b)
{
    if (a > b)
        return a;
    return b;
}
void solve(string s)
{
    stringstream ss(s);
    string str;
    vector<string> each;
    string credit = "";
    while (ss >> str)
    {
        if (credit == "" && (str == "1.0" || str == "2.0" || str == "3.0"))
        {
            credit = str;
        }
        else if (str.size() <= 4)
        {
            each.push_back(str);
        }
    }
    if (each.size() > 2)
    {
        str = each[0] + each[1];
        result[str].second = stod(credit);
        result[str].first = max(result[str].first, stod(each[each.size() - 1]));
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    string str;
    while (getline(cin, str))
    {
        solve(str);
    }
    double total_point = 0, total_credit = 0;
    for (auto it : result)
    {
        total_point += (it.second.first * it.second.second);
        total_credit += it.second.second;
    }
    cout << "Total point  = " << total_point << endl;
    cout << "Total Credit = " << total_credit << endl;
    cout << "CGPA         = " << total_point / total_credit << endl;
    return 0;
}