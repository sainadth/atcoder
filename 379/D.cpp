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
    int q;
    cin >> q;
    priority_queue<int> pq;
    vector<priority_queue<int>> vpq;
    int wt = 0;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            if (wt > 0)
            {
                vpq.push_back(pq);
            }

            vpq.push_back()
                pq.();
            pq.push(0);
        }
        else
        {
            int x;
            cin >> x;
            if (type == 2)
            {
                wt = x;
            }
            else
            {
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
    // cout << (t2 - t1) / 1000.0 << endl;
    return 0;
}