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

int bfs(int s, map<int, vector<int>> &adjList, map<int, int> &deg){
    queue<int> q;
    q.push(s);
    map<int, int> vis;
    vis[s] = 1;
    int res = 1;
    cout << s << " ";
    while(q.size()){
        int u = q.front();
        q.pop();
        for(auto v : adjList[u]){
            if(vis.count(v) == 0){
                vis[v] = 1;
                if(deg[v] == 1 || deg[v] == 4){
                    res++;
                    q.push(v);
                    cout << v << " ";
                }
            }
        }
    }
    cout << endl;
    return res;
}

void solve()
{
    int n;
    cin >> n;
    map<int, vector<int>> adjList;
    map<int, int> deg;
    n--;
    while(n--){
        int u, v;
        cin >> u >> v;
        adjList[u].pb(v);
        adjList[v].pb(u);
        deg[u]++;
        deg[v]++;
    }
    int res = 0;
    for(auto [k, v] : deg){
        if(v == 4){
            res = max(res, bfs(k, adjList, deg));
        }
        cout << res << endl;
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