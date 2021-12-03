#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define Size 1000000
vector<lli> divisors, input;

class segmentTree_
{
private:
    lli total;
    vector<lli> segmentTree, lazy;

public:
    segmentTree_(lli size)
    {
        total = size;
        lli x = (lli)(ceil(log2(total)));
        lli max_size = 2 * (lli)pow(2, x) - 1;
        segmentTree.resize(max_size+10);
        lazy.resize(max_size+10);
        fill(segmentTree.begin(), segmentTree.end(), 0);
        fill(lazy.begin(), lazy.end(), 0);
    }
    lli updateSegmentTreeRangeLazy(lli q_low, lli q_high, lli start, lli End, lli pos)
    {
        if (start > End)
            return 0;
        lli left = pos * 2 + 1;
        lli right = pos * 2 + 2;
        lli change = 0;
        // If already completed then return
        if (lazy[pos] == 2)
        {
            return 0;
        }
        //no overlap condition
        if (q_low > End || q_high < start)
            return 0;

        //total overlap condition
        if (q_low <= start && q_high >= End)
        {

            if (start == End)
            {
                lli prev = segmentTree[pos];
                segmentTree[pos] = divisors[prev];
                if (segmentTree[pos] < 3)
                {
                    lazy[pos] = 2;
                }
                // cout<<left<<" "<<right<<" "<<pos<<endl;
                // printf("%d %d,\tprev=%d\tchange=%d\tnow=%d\n", start, End, prev, segmentTree[pos] - prev, segmentTree[pos]);
                return segmentTree[pos] - prev;
            }
        }
        if (lazy[left] == 2 && lazy[right] == 2)
        {
            lazy[pos] = 2;
            return 0;
        }
        //otherwise partial overlap so look both left and right.
        lli mid = (start + End) / 2;
        change += updateSegmentTreeRangeLazy(q_low, q_high, start, mid, left);
        change += updateSegmentTreeRangeLazy(q_low, q_high, mid + 1, End, right);
        segmentTree[pos] += change;
        return change;
    }

    lli rangeMinimumQueryLazy(lli q_low, lli q_high, lli start, lli End, lli pos)
    {
        if (start > End)
            return 0;
        //make sure all propagation is done at pos. If not update tree
        //at pos and mark its children for lazy propagation.
        lli left = pos * 2 + 1;
        lli right = pos * 2 + 2;
        // If already completed then return
        // if (lazy[pos] == 2)
        // {
        //     return segmentTree[pos];
        // }
        //no overlap
        if (q_low > End || q_high < start)
            return 0;
        //total overlap
        if (q_low <= start && q_high >= End)
        {
            // printf("sum-> %d %d %d\n", pos, start, End);
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
            lazy[pos] = 0;
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
    void updateRange(lli lo, lli hi)
    {
        updateSegmentTreeRangeLazy(lo, hi, 0, total - 1, 0);
    }
    lli getSum(lli lo, lli hi)
    {
        if (lo < 0 || hi > total - 1 || lo > hi)
            return -1;
        return rangeMinimumQueryLazy(lo, hi, 0, total - 1, 0);
    }
    void prlli_seg(lli n)
    {
       for(auto it : segmentTree)printf("%lld, ", it);
        puts("");
    }
};

void findDivisors(lli n)
{
    divisors.resize(n + 1);
    for (lli i = 1; i <= n; i++)
    {
        for (lli j = 1; j * i <= n; j++)
        {
            divisors[i * j]++;
        }
    }
}

int main()
{
    // freopen("input.txt", "r", stdin);
    findDivisors(Size);

    lli n, m, x, l, r;
    scanf("%lld%lld", &n, &m);
    input.resize(n);

    segmentTree_ object = segmentTree_(n);
    for (lli i = 0; i < n; i++)
    {
        scanf("%lld", &input[i]);
    }

    // object.prlli_seg(16);
    object.constructSTUtil(input, 0, n-1, 0);
    // object.prlli_seg(16);
    while (m--)
    {
        scanf("%lld%lld%lld", &x, &l, &r);
        l--, r--;
        if (x == 1)
        {
            object.updateRange(l, r);
            // object.prlli_seg(16);
        }
        else
        {
            printf("%lld\n", object.getSum(l, r));
        }
    }
}
