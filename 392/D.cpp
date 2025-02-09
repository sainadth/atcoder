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
    vector<map<int, double>> prob(n);
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        map<int, int> mp;
        for(int j = 0; j < k; j++){
            int x;
            cin >> x;
            mp[x]++;
        }
        for(auto &j : mp){
            prob[i][j.first] = j.second / (double)k;
        }
    }
    double ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            double temp = 0;
            for(auto &k : prob[i]){
                if(prob[j].count(k.first) == 0) continue;
                temp += k.second * prob[j][k.first];
            }
            ans = max(ans, temp);
        }
    }
    cout << setprecision(10) << ans << endl;
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