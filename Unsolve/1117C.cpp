#include <bits/stdc++.h>
using namespace std;
int leftx[] = {-1, -1, -1, 2};
int lefty[] = {0, 1, -1, 0};

int rightx[] = {1, 1, 2, 1};
int righty[] = {0, 1, 0, -1};

int upx[] = {0, -1, 0, 1};
int upy[] = {1, 1, 2, 1};

int downx[] = {0, -1, 1, 0};
int downy[] = {-1, -1, -1, 2};

map<pair<int, int>, bool> mark;
pair<int, int> temp_pair;
stack<pair<int, int>> stk;

int upper_l, lower_l, left_l, right_l;
bool upper_p, lower_p, left_p, right_p;

bool check(int x, int y);
bool left(int x, int y);
bool right(int x, int y);
bool up(int x, int y);
bool down(int x, int y);

void bfs(int x, int y, int x1, int y1, string &sss)
{
    stk.push(make_pair(x, y));
    for (auto it : sss)
    {
        if (it == 'L')
        {
            while (!stk.empty())
            {
                temp_pair = stk.top(), stk.pop();
                left(temp_pair.first, temp_pair.second);
            }
        }
        else if (it == 'R')
        {
            while (!stk.empty())
            {
                temp_pair = stk.top(), stk.pop();
                right(temp_pair.first, temp_pair.second);
            }
        }
        else if (it == 'U')
        {
            while (!stk.empty())
            {
                temp_pair = stk.top(), stk.pop();
                up(temp_pair.first, temp_pair.second);
            }
        }
        else if (it == 'D')
        {
            while (!stk.empty())
            {
                temp_pair = stk.top(), stk.pop();
                down(temp_pair.first, temp_pair.second);
            }
        }
    }
}
int main()
{
    int x, y, x1, y1, n;
    string sss;
    scanf("%d%d%d%d", &x, &y, &x1, &y1);
    if (x > x1)
        left_p = true;
    else if (x1 > x)
        right_p = true;
    if (y > y1)
        lower_p = true;
    else if (y < y1)
        upper_p = true;

    upper_l = max(y, y1);
    lower_l = min(y, y1);
    left_l = min(x, x1);
    right_l = max(x, x1);

    cin >> n >> sss;
    return 0;
}

bool check(int x, int y)
{
    return x >= left_l and x <= right_l && y >= lower_l && y <= upper_l;
}
bool left(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        temp_pair = make_pair(leftx[i] + x, lefty[i] + y);
        if (!mark[temp_pair] && check(temp_pair.first, temp_pair.second))
        {
            mark[temp_pair] = true;
            stk.push(temp_pair);
        }
    }
}

bool right(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        temp_pair = make_pair(rightx[i] + x, righty[i] + y);
        if (!mark[temp_pair] && check(temp_pair.first, temp_pair.second))
        {
            mark[temp_pair] = true;
            stk.push(temp_pair);
        }
    }
}

bool up(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        temp_pair = make_pair(upx[i] + x, upy[i] + y);
        if (!mark[temp_pair] && check(temp_pair.first, temp_pair.second))
        {
            mark[temp_pair] = true;
            stk.push(temp_pair);
        }
    }
}

bool down(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        temp_pair = make_pair(downx[i] + x, downy[i] + y);
        if (!mark[temp_pair] && check(temp_pair.first, temp_pair.second))
        {
            mark[temp_pair] = true;
            stk.push(temp_pair);
        }
    }
}