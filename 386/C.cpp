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
    int k;
    string s, t;
    cin >> k >> s >> t;
    int a = 1, d = 1, u = 1;
    if (s.size() == t.size() - 1)
    {
        long unsigned int i = 0, j = 0;
        while (i < s.size() && j < t.size())
        {
            if (s[i] == t[j])
            {
                i++;
                j++;
            }
            else
            {
                if (a == 0)
                    return "No";
                a = 0;
                j++;
            }
        }
        return "Yes";
    }
    else if (s.size() == t.size() + 1)
    {
        long unsigned int i = 0, j = 0;
        while (i < s.size() && j < t.size())
        {
            if (s[i] == t[j])
            {
                i++;
                j++;
            }
            else
            {
                if (d == 0)
                    return "No";
                d = 0;
                i++;
            }
        }
        return "Yes";
    }
    else if (s.size() == t.size())
    {
        long unsigned int i = 0;
        while (i < s.size())
        {
            if (s[i] != t[i])
            {
                if (u == 0)
                    return "No";
                u = 0;
            }
            i++;
        }
        return "Yes";
    }
    else
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