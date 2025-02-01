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
    int c = 0;
    for(int i = 1; i < 6; i++){
        int temp;
        cin >> temp;
        if(temp > i + 1 || temp < i - 1){
            cout << "NO\n";
            return;
        }
        if(temp != i && temp < i + 2 && temp > i - 2) c++;
    }
    /* 2 5 3 4 1 */
    cout << (c == 2 ? "YES" : "NO") << '\n';
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