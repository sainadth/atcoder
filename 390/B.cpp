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
    int n;
    cin >> n;
    vector<long long> v(n);
    for(auto &i : v) cin >> i;
    if(n == 2) return "Yes";
    /* 
        a ar ar^2 
        a * ar^2 = ar * ar
    */
    for(int i = 0; i < n - 2; i++){
        long long a = v[i] * v[i + 2];
        long long b = v[i + 1] * v[i + 1];
        if(a != b) return "No";
    }
    return "Yes";
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