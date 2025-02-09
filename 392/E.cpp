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

class DSU{
    vector<int> parent;
public:
    DSU(int n){
        parent.resize(n);
        int j = 0;
        for(auto &i : parent) i = j++;
    }

    int Find(int x){
        if(parent[x] == x) return x;
        return parent[x] = Find(parent[x]);
    }

    bool Union(int x, int y){
        int x_parent = Find(x);
        int y_parent = Find(y);

        if(x_parent != y_parent){
            if(x_parent < y_parent) parent[y_parent] = x_parent;
            else parent[x_parent] = y_parent;
            return true;
        }
        return false;
    }
};

void solve()
{
    DSU* network;

    int n, m;
    cin >> n >> m;
    map<int, vector<int>> groups;
    vector<int> gids;
    network = new DSU(n);
    while(m--){
        int x, y;
        cin >> x >> y;
        x--, y--;
        network->Union(x, y);
        int pa = network->Find(x);
        groups[pa].pb(x);
        groups[pa].pb(y);
    }

    for(auto &i : groups){
        gids.pb(i.first);
    }
    int res = groups.size() - 1;
    cout << res << endl;
    for(int i = 0; i < gids.size(); i++){
        for(int j = i + 1; j < gids.size(); j++){
            
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