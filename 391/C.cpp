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
    int n, q;
    cin >> n >> q;
    int c = 0;
    vector<int> p(n);
    vector<int> h(n, 1);
    int j = 0;
    for(auto &i : p) i = j++;
    while(q--){
        int t;
        cin >> t;
        switch (t)
        {
        case 1:
            int a, b;
            cin >> a >> b;
            a--; b--;
            h[p[a]]--;
            if(h[p[a]] == 1) c--;
            p[a] = b;
            h[b]++;
            if(h[b] == 2) c++;
            break;
        
        case 2:
            cout << c << endl;
            break;
        default:
            break;
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