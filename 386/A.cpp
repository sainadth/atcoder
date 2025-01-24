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

string solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    map<int, int> mp;
    mp[a]++;
    mp[b]++;
    mp[c]++;
    mp[d]++;
    bool three = false;
    bool one = false;
    int two = 0;
    for (auto i : mp)
    {
        int v = i.second;
        if (v == 3)
            three = true;
        else if (v == 2)
            two++;
        else if (v == 1)
            one = true;
    }
    if ((three && one) || (two == 2))
        return "Yes";

    return "No";
}

int main()
{
    // double t1 = clock();
    // srand(time(0));

    flash;
    cout << solve();

    // double t2 = clock();
    // cerr << (t2 - t1) / 1000.0 << endl;
    return 0;
}