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
    int n;
    cin >> n;

    vector<int> v(n);
    map<int, int> mp;
    for(auto &i : v){
        cin >> i;
        mp[i]++;
    }

    int res = -1, ans = -1;

    for(int i = 0; i < n; i ++){
        if(mp[v[i]] == 1){
            if(res < v[i]){
                res = v[i];
                ans = i + 1;
            }
        }
    }

    cout << ans << endl;
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