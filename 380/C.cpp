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
    vector<pair<char, int>> v;
    int c = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (i && s[i] != s[i - 1])
        {
            v.push_back({s[i - 1], c});
            c = 1;
        }
        else
        {
            c++;
        }
    }
    v.push_back({s.back(), c});
    string res = "";
    string temp = "";
    for (int i = 0; i < v.size(); i++)
    {
        if (k == 1 && temp == "")
        {
            temp = string(v[i].second, v[i].first);
            continue;
        }
        if (v[i].first == '1')
            k--;
        res += string(v[i].second, v[i].first);
        if (k == 0)
        {
            res += temp;
            temp = "";
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
    // cerr << (t2 - t1) / 1000.0 << endl;
    return 0;
}