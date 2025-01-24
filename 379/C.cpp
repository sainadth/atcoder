#include <bits/stdc++.h>
using namespace std;
/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> multi_ordered_set;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
*/
// #define int long long
#define pb push_back
#define flash ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(v) v.begin(), v.end()

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<long long> st(n, 0);
    vector<int> sti(m);
    for (auto &i : sti)
        cin >> i;
    long long total = 0;
    for (auto i : sti)
    {
        cin >> st[i - 1];
        total += st[i - 1];
    }
    if (total % n)
    {
        cout << -1 << endl;
        return;
    }
    long long k = total / n;
    int cur = n - 1;
    long long res = 0;
    for (int i = n - 1; i >= 0 && cur > 0; i--)
    {
        while (st[i] > 0 && cur > i)
        {
            long long transfer = min(k - st[cur], st[i]);
            res += transfer * (cur - i);
            st[cur] += transfer;
            st[i] -= transfer;
            cur--;
        }
        if (cur == i)
        {
            if (st[i] > k)
                break;
        }
    }
    if (st[0] != k || cur != 0)
        cout << -1 << endl;
    else
        cout << res << endl;
}

int main()
{
    // double t1 = clock();
    // srand(time(0));
    flash;
    solve();

    // double t2 = clock();
    // cout << (t2 - t1) / 1000.0 << endl;
    return 0;
}