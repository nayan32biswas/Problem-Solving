#include <bits/stdc++.h>
using namespace std;
struct node
{
    int one, two, zero, lazy;
};
vector<node> segmentTree;
void swap(int pos);
void step_shift(int pos, int value);
void constructSTUtil(int start, int End, int pos);
int rangeMinimumQueryLazy(int q_low, int q_high, int low, int high, int pos);
void updateSegmentTreeRangeLazy(int q_low, int q_high, int delta, int low, int high, int pos);
void updateRange(int n, int lo, int hi, int value)
{
    updateSegmentTreeRangeLazy(lo, hi, value, 0, n - 1, 0);
}
int getSum(int n, int lo, int hi)
{
    if (lo < 0 || hi > n - 1 || lo > hi)
        return -1;
    return rangeMinimumQueryLazy(lo, hi, 0, n - 1, 0);
}
void solve()
{
    int n, q, t, x, y;
    scanf("%d%d", &n, &q);
    segmentTree.resize(n * 4);
    constructSTUtil(0, n - 1, 0);
    while (q--)
    {
        scanf("%d%d%d", &t, &x, &y);
        if (t)
        {
            // printf("%d %d %d\n", t, x, y);
            printf("%d\n", getSum(n, x, y));
        }
        else
        {
            // printf("%d %d %d %d\n", t, x, y, v);
            updateRange(n, x, y, 1); // 1 is incriment value
        }
        // for(auto it : segmentTree){
        //     printf("%d %d %d %d\n", it.zero, it.one, it.two, it.lazy);
        // }
        // puts("");
    }
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int test, n;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        printf("Case %d:\n", t);
        solve();
    }
}
void swap(int pos)
{
    // printf("start: %d %d %d\n", segmentTree[pos].zero, segmentTree[pos].one, segmentTree[pos].two);
    int temp = segmentTree[pos].two;
    segmentTree[pos].two = segmentTree[pos].one;
    segmentTree[pos].one = segmentTree[pos].zero;
    segmentTree[pos].zero = temp;
    // printf("end: %d %d %d\n", segmentTree[pos].zero, segmentTree[pos].one, segmentTree[pos].two);
}
void step_shift(int pos, int left, int right, int value)
{
    value %= 3;
    int temp;
    // cout<<"\nvalue: "<<value<<endl;
    while (value--)
    {
        swap(pos);
    }
    // segmentTree[pos].zero = segmentTree[left].zero + segmentTree[right].zero;
    // segmentTree[pos].one = segmentTree[left].one + segmentTree[right].one;
    // segmentTree[pos].two = segmentTree[left].two + segmentTree[right].two;
}
void updateSegmentTreeRangeLazy(int q_low, int q_high, int delta, int start, int End, int pos)
{
    if (start > End)
        return;
    //make sure all propagation is done at pos. If not update tree
    //at pos and mark its children for lazy propagation.
    int left = pos * 2 + 1;
    int right = pos * 2 + 2;
    if (segmentTree[pos].lazy != 0)
    {
        // segmentTree[pos] += segmentTree[pos].lazy;
        step_shift(pos, left, right, segmentTree[pos].lazy);
        if (start != End)
        {
            //not a leaf node
            segmentTree[left].lazy += segmentTree[pos].lazy;
            segmentTree[right].lazy += segmentTree[pos].lazy;
        }
        segmentTree[pos].lazy = 0;
    }
    //no overlap condition
    if (q_low > End || q_high < start)
        return;
    //total overlap condition
    if (q_low <= start && q_high >= End)
    {
        step_shift(pos, left, right, delta);
        if (start != End)
        {
            segmentTree[left].lazy += delta;
            segmentTree[right].lazy += delta;
        }
        return;
    }
    //otherwise partial overlap so look both left and right.
    int mid = (start + End) / 2;
    updateSegmentTreeRangeLazy(q_low, q_high, delta, start, mid, left);
    updateSegmentTreeRangeLazy(q_low, q_high, delta, mid + 1, End, right);
    segmentTree[pos].zero = segmentTree[left].zero + segmentTree[right].zero;
    segmentTree[pos].one = segmentTree[left].one + segmentTree[right].one;
    segmentTree[pos].two = segmentTree[left].two + segmentTree[right].two;
}

int rangeMinimumQueryLazy(int q_low, int q_high, int start, int End, int pos)
{
    if (start > End)
        return 0;
    //make sure all propagation is done at pos. If not update tree
    //at pos and mark its children for lazy propagation.
    int left = pos * 2 + 1;
    int right = pos * 2 + 2;
    if (segmentTree[pos].lazy != 0)
    {
        // segmentTree[pos] += segmentTree[pos].lazy;
        step_shift(pos, left, right, segmentTree[pos].lazy);
        if (start != End)
        {
            //not a leaf node
            segmentTree[left].lazy += segmentTree[pos].lazy;
            segmentTree[right].lazy += segmentTree[pos].lazy;
        }
        segmentTree[pos].lazy = 0;
    }
    //no overlap
    if (q_low > End || q_high < start)
        return 0;
    //total overlap
    if (q_low <= start && q_high >= End)
    {
        // printf("zero: %d\n", segmentTree[pos].zero);
        return segmentTree[pos].zero;
    }
    //partial overlap
    int mid = (start + End) / 2;
    return rangeMinimumQueryLazy(q_low, q_high, start, mid, left) + rangeMinimumQueryLazy(q_low, q_high, mid + 1, End, right);
}
void constructSTUtil(int start, int End, int pos)
{
    if (start > End)
        return;
    if (start == End)
    {
        segmentTree[pos].zero = 1;
        segmentTree[pos].one = segmentTree[pos].two = segmentTree[pos].lazy = 0;
        return;
    }
    int left = pos * 2 + 1;
    int right = pos * 2 + 2;
    int mid = (start + End) / 2;
    constructSTUtil(start, mid, left);
    constructSTUtil(mid + 1, End, right);
    segmentTree[pos].lazy = 0;
    segmentTree[pos].zero = segmentTree[left].zero + segmentTree[right].zero;
    segmentTree[pos].one = segmentTree[left].one + segmentTree[right].one;
    segmentTree[pos].two = segmentTree[left].two + segmentTree[right].two;
}