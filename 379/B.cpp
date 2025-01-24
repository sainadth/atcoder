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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int res = 0;
    int cur = 0;
    for (auto i : s)
    {
        if (i == 'O')
            cur++;
        else
            cur = 0;
        if (cur == k)
        {
            cur = 0;
            res++;
        }
    }
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