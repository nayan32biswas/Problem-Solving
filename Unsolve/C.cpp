#include <bits/stdc++.h>
using namespace std;
struct node
{
    int open, close, match;
};
vector<node> segmentTree;
void constructSTUtil(string &input, int start, int End, int pos);
int rangeMinimumQueryLazy(int q_low, int q_high, int low, int high, int pos);
void updateSegmentTreeRangeLazy(int q_low, int q_high, int delta, int low, int high, int pos);
int getSum(int n, int lo, int hi)
{
    if (lo < 0 || hi > n - 1 || lo > hi)
        return -1;
    return rangeMinimumQueryLazy(lo, hi, 0, n - 1, 0);
}
void solve()
{
    string str;
    cin >> str;
    int q, lo, hi, n = str.size();
    segmentTree.resize(n * 4);
    constructSTUtil(str, 0, n - 1, 0);
    scanf("%d", &q);
    // q = 0;
    while (q--)
    {
        scanf("%d%d", &lo, &hi);
        lo--, hi--;
        printf("%d\n", getSum(n, lo, hi) * 2);
        // printf("%d\n", count_balanced(str, lo, hi));
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    solve(); // submission to check vartext TLE or not
    return 0;
}

int rangeMinimumQueryLazy(int q_low, int q_high, int start, int End, int pos)
{
    if (start > End)
        return 0;
    //make sure all propagation is done at pos. If not update tree
    //at pos and mark its children for lazy propagation.
    int left = pos * 2 + 1;
    int right = pos * 2 + 2;

    if (q_low > End || q_high < start)
        return 0;
    //total overlap
    if (q_low <= start && q_high >= End)
    {
        int temp = min(segmentTree[pos].open, segmentTree[pos].close);
        return segmentTree[pos].match + temp;
    }
    //partial overlap
    int mid = (start + End) / 2;
    return rangeMinimumQueryLazy(q_low, q_high, start, mid, left) + rangeMinimumQueryLazy(q_low, q_high, mid + 1, End, right);
}
void constructSTUtil(string &input, int start, int End, int pos)
{
    if (start > End)
        return;
    if (start == End)
    {
        segmentTree[pos].match = 0;
        if (input[start] == '(')
            segmentTree[pos].open = 1;
        else
            segmentTree[pos].close = 1;
        return;
    }
    int left = pos * 2 + 1;
    int right = pos * 2 + 2;
    int mid = (start + End) / 2;
    constructSTUtil(input, start, mid, left);
    constructSTUtil(input, mid + 1, End, right);
    // segmentTree[pos].open = segmentTree[left].open;
    // segmentTree[pos].close = segmentTree[right].close;

    int temp = min(segmentTree[left].open, segmentTree[right].close);
    segmentTree[pos].match = segmentTree[left].match + segmentTree[right].match;
    segmentTree[pos].match += temp;

    segmentTree[pos].open = segmentTree[left].open - temp + segmentTree[right].open;
    segmentTree[pos].close = segmentTree[right].close - temp + segmentTree[left].close;
}