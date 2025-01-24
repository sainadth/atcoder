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

int solve()
{
    int m, n;
    cin >> m >> n;
    vector<vector<char>> grid(m, vector<char>(n));
    pair<int, int> s, g;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
                s = {i, j};
            if (grid[i][j] == 'G')
                g = {i, j};
        }
    }
    map<pair<pair<int, int>, int>, int> vis;
    queue<pair<pair<int, int>, int>> q;
    q.push({s, -1});
    int level = 0;
    while (!q.empty())
    {
        int t = q.size();
        while (t--)
        {
            auto t = q.front();
            q.pop();
            // cout << "{ { " << t.first.first << ", " << t.first.second << "}, " << t.second << " } ";
            vis[t] = 1;
            if (t.first == g)
                return level;
            if (t.second != 0)
            {
                if (t.first.first + 1 < m)
                {
                    if (grid[t.first.first + 1][t.first.second] != '#' && vis.count({{t.first.first + 1, t.first.second}, 0}) == 0)
                        q.push({{t.first.first + 1, t.first.second}, 0});
                }
                if (t.first.first - 1 >= 0)
                {
                    if (grid[t.first.first - 1][t.first.second] != '#' && vis.count({{t.first.first - 1, t.first.second}, 0}) == 0)
                        q.push({{t.first.first - 1, t.first.second}, 0});
                }
            }
            if (t.second != 1)
            {

                if (t.first.second + 1 < n)
                {
                    if (grid[t.first.first][t.first.second + 1] != '#' && vis.count({{t.first.first, t.first.second + 1}, 1}) == 0)
                        q.push({{t.first.first, t.first.second + 1}, 1});
                }
                if (t.first.second - 1 >= 0)
                {
                    if (grid[t.first.first][t.first.second - 1] != '#' && vis.count({{t.first.first, t.first.second - 1}, 1}) == 0)
                        q.push({{t.first.first, t.first.second - 1}, 1});
                }
            }
        }
        level++;
        // cout << endl;
    }
    return -1;
}

int main()
{
    // double t1 = clock();
    // srand(time(0));

    flash;
    cout << solve() << endl;

    // double t2 = clock();
    // cerr << (t2 - t1) / 1000.0 << endl;
    return 0;
}