#include <bits/stdc++.h>
using namespace std;

#define flash ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(v) v.begin(), v.end()

#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<long long> tree, lazy;

public:
    SegmentTree(vector<int> &nums)
    {
        tree.resize(4 * nums.size() + 1, 0);
        lazy.resize(4 * nums.size() + 1, 0);
        build(0, 0, nums.size() - 1, nums);
    }

    void build(int i, int l, int r, vector<int> &nums)
    {
        if (l == r)
        {
            tree[i] = nums[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * i + 1, l, m, nums);
        build(2 * i + 2, m + 1, r, nums);
        tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    }

    void update(int i, int l, int r, long long v)
    {
        lazy[i] += v;
        tree[i] += (r - l + 1) * v;
    }

    void push(int i, int l, int r)
    {
        int m = (l + r) / 2;
        update(2 * i + 1, l, m, lazy[i]);
        update(2 * i + 2, m + 1, r, lazy[i]);
        lazy[i] = 0;
    }

    void updateRange(int i, int l, int r, int rl, int rr, int v)
    {
        if (rl > rr)
            return;
        if (l == rl && r == rr)
        {
            update(i, l, r, v);
            return;
        }
        int m = (l + r) / 2;
        push(i, l, r);
        updateRange(2 * i + 1, l, m, rl, min(m, rr), v);
        updateRange(2 * i + 2, m + 1, r, max(m + 1, rl), rr, v);
    }

    long long get(int i, int l, int r, int k)
    {
        if (l == r)
            return tree[i];
        int m = (l + r) / 2;
        push(i, l, r);
        if (k <= m)
            return get(2 * i + 1, l, m, k);
        return get(2 * i + 2, m + 1, r, k);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto &i : nums)
        cin >> i;
    SegmentTree *s = new SegmentTree(nums);
    for (int i = 0; i < n; i++)
    {
        int cur = s->get(0, 0, n - 1, i);
        cout << cur << " -- ";
        if (cur > 0)
        {
            int t = max(0, cur - n + 1);
            cout << t << " ";
            s->update(i, 0, n - 1, max(-cur, -cur + t));
            s->updateRange(0, 0, n - 1, i + 1, min(n - 1, i + cur), 1);
        }
        cout << s->get(0, 0, n - 1, i) << endl;
    }
    cout << endl;
}

int main()
{
    // double t1 = clock();
    // srand(time(0));

    flash;
    solve();

    // double t2 = clock();
    // cerr << (t2 - t1) / 1000.0 << endl;
    return 0;
}