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
    vector<int> v(3, 0);
    for (auto &i : v)
    {
        i = n % 10;
        n /= 10;
    }
    string resa = "", resb = "";
    resa += v[1] + '0';
    resa += v[0] + '0';
    resa += v[2] + '0';

    resb += v[0] + '0';
    resb += v[2] + '0';
    resb += v[1] + '0';
    cout << resa << " " << resb << endl;
}

int main()
{
    /* double t1 = clock();
    srand(time(0)); */
    flash;
    /* int te;
    cin >> te;
    for (int i = 0; i < te; i++) */
    solve();

    /* double t2 = clock();
    cout << (t2 - t1) / 1000.0 << endl; */
    return 0;
}