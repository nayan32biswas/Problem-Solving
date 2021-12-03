#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/* Head ends here */

vector<int> arr;
void insert(int a)
{
    auto iter = upper_bound(arr.begin(), arr.end(), a);
    arr.insert(iter, a);
}
bool remove(int a)
{
    auto iter = lower_bound(arr.begin(), arr.end(), a);
    if ((iter == arr.end()) || (*iter != a))
    {
        return false;
    }
    else
    {
        arr.erase(iter);
        return true;
    }
}
void find()
{
    int len = arr.size();
    if (arr.empty())
    {
        cout << "Wrong!" << endl;
        return;
    }
    if ((len % 2) == 0)
    {
        int i = len / 2;
        double x = 0.5 * (double(arr[i - 1]) + double(arr[i]));
        cout << x << endl;
    }
    else
        cout << arr[len / 2] << endl;
}
void median(vector<char> s, vector<int> X)
{
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'a')
        {
            insert(X[i]);
            find();
        }
        else if (s[i] == 'r')
        {
            if (remove(X[i]))
                find();
            else
                cout << "Wrong!" << endl;
        }
    }
}
int main(void)
{
    // freopen("input.txt", "r", stdin);
    cout.precision( 14 );
    int N;
    cin >> N;
    vector<char> s;
    vector<int> X;
    char temp;
    int tempint;
    for (int i = 0; i < N; i++)
    {
        cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
    }

    median(s, X);
    return 0;
}