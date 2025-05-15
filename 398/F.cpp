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

vector<int> manacher_odd(string s) {
    cout << s << endl;
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}


vector<int> manacher(string s) {
    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto res = manacher_odd(t + "#");
    return vector<int>(begin(res) + 1, end(res) - 1);
}

void solve()
{
    string s;
    cin >> s;

    string ans = s;

    auto res = manacher(s);
    int n = s.size();

    for(auto i : res) cout << i << " ";
    cout << endl;

    for(int i = 1; i < 2 * n; i += 2){
        cout << res[i] << " ";
        if(i + 1 + res[i] == n){
            for(int j = i; j >= 0; j--){
                ans += s[j];
            }
            cout << ans << endl;
            return;
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