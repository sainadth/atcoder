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
    string s;
    cin >> n >> s;
    vector<pair<long long, int>> lp(n, {0, 0}), rp(n, {0, 0});


    if(s[0] == '1') lp[0] = {0, 1};
    for(int i = 1; i < n; i++){
        if(s[i] == '1')
            lp[i] = {lp[i - 1].first, lp[i - 1].second + 1};
        else 
            lp[i] = {lp[i - 1].first + lp[i - 1].second, lp[i - 1].second};
    }
    
    
    if(s[n - 1] == '1') rp[n - 1] = {0, 1};
    for(int i = n - 2; i >= 0; i--){
        if(s[i] == '1')
            rp[i] = {rp[i + 1].first, rp[i + 1].second + 1};
        else 
            rp[i] = {rp[i + 1].first + rp[i + 1].second, rp[i + 1].second};
    }

    long long res = LLONG_MAX;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') res = min(res, lp[i].first + rp[i].first);
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