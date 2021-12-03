#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

class segmentTree_
{
private:
    lli total;
    vector<lli> segmentTree, lazy;

public:
    lli change;
    segmentTree_(lli size)
    {
        total = size;
        lli x = (lli)(ceil(log2(total)));
        lli max_size = 2 * (lli)pow(2, x) - 1;
        segmentTree.resize(max_size + 10);
        fill(segmentTree.begin(), segmentTree.end(), 0);
        lazy.resize(max_size + 10);
        fill(lazy.begin(), lazy.end(), 0);
    }
    void print_seg()
    {
        for (auto it : segmentTree)
            printf("%lld, ", it);
        puts("");
    }
    void updateSegmentTreeRangeLazy(lli q_low, lli q_high, lli delta, lli start, lli End, lli pos)
    {
        if (start > End)
            return;
        lli left = pos * 2 + 1;
        lli right = pos * 2 + 2;
        //no overlap condition
        if (q_low > End || q_high < start)
            return;
        //total overlap condition
        if (q_low <= start && q_high >= End)
        {
            if (start == End)
            {
                segmentTree[pos] += delta;
                if (change < 0)
                {
                    change = -segmentTree[pos];
                    segmentTree[pos] = 0;
                }
                else
                {
                    change = delta;
                    return;
                }
            }
            return;
        }
        lli mid = (start + End) / 2;
        updateSegmentTreeRangeLazy(q_low, q_high, delta, start, mid, left);
        updateSegmentTreeRangeLazy(q_low, q_high, delta, mid + 1, End, right);
        segmentTree[pos] += change;
    }

    lli rangeMinimumQueryLazy(lli q_low, lli q_high, lli start, lli End, lli pos)
    {
        if (start > End)
            return 0;
        lli left = pos * 2 + 1;
        lli right = pos * 2 + 2;
        //no overlap
        if (q_low > End || q_high < start)
            return 0;
        //total overlap
        if (q_low <= start && q_high >= End)
        {
            return segmentTree[pos];
        }
        //partial overlap
        lli mid = (start + End) / 2;
        return rangeMinimumQueryLazy(q_low, q_high, start, mid, left) + rangeMinimumQueryLazy(q_low, q_high, mid + 1, End, right);
    }

    void constructSTUtil(vector<lli> &input, lli start, lli End, lli pos)
    {
        if (start > End)
            return;
        if (start == End)
        {
            segmentTree[pos] = input[start];
            return;
        }
        lli left = pos * 2 + 1;
        lli right = pos * 2 + 2;
        lli mid = (start + End) / 2;
        constructSTUtil(input, start, mid, left);
        constructSTUtil(input, mid + 1, End, right);

        segmentTree[pos] = segmentTree[left] + segmentTree[right];
    }
    void updateRange(lli lo, lli hi, lli value)
    {
        updateSegmentTreeRangeLazy(lo, hi, value, 0, total - 1, 0);
    }
    lli getSum(lli lo, lli hi)
    {
        if (lo < 0 || hi > total - 1 || lo > hi)
            return -1;
        return rangeMinimumQueryLazy(lo, hi, 0, total - 1, 0);
    }
};

int main()
{
    // freopen("input.txt", "r", stdin);

    lli n, m, x, l, r, v, test;
    vector<lli> input;

    scanf("%lld", &test);
    for (lli t = 1; t <= test; t++)
    {
        printf("Case %lld:\n", t);

        scanf("%lld%lld", &n, &m);
        input.resize(n);

        segmentTree_ object = segmentTree_(n);
        for (lli i = 0; i < n; i++)
        {
            scanf("%lld", &input[i]);
        }
        // for (int i = 0; i < n; i++)
        //     cout << input[i] << ", ";
        // puts("");

        object.constructSTUtil(input, 0, n - 1, 0);
        // object.print_seg();
        while (m--)
        {
            object.change = 0;
            scanf("%lld%lld", &x, &l);
            if (x == 1)
            {
                object.change = -1;
                object.updateRange(l, l, 0);
                // puts("make empty");
                // object.print_seg();
                printf("%lld\n", -object.change);
            }
            else if (x == 2)
            {
                object.change = 0;
                scanf("%lld", &v);
                object.updateRange(l, l, v);
                // puts("add fully");
                // object.print_seg();
            }
            else
            {
                scanf("%lld", &r);
                printf("%lld\n", object.getSum(l, r));
            }
        }
    }
}
