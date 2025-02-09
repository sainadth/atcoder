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
    vector<string> s(n), t(m);
    for(auto &i : s) cin >> i;
    for(auto &i : t) cin >> i;
    for(int i = 0; i < n - m + 1; i++)
    {
        for(int j = 0; j < n - m + 1; j++)
        {
            bool ok = true;
            for(int k = 0; k < m; k++)
            {
                for(int l = 0; l < m; l++)
                {
                    if(s[i + k][j + l] != t[k][l])
                    {
                        ok = false;
                        break;
                    }
                }
                if(!ok) break;
            }
            if(ok)
            {
                cout << i + 1 << " " << j + 1 << endl;
                return;
            }
        }
    }
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