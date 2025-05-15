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
    string s;
    cin >> s;
    stack<char> st;
    for(auto i : s){
        if(st.size() == 0){
            st.push(i);
        }else if(i == ']'){
            if(st.top() == '[') st.pop();
            else st.push(i);
        }else if(i == ')'){
            if(st.top() == '(') st.pop();
            else st.push(i);
        }else if(i == '>'){
            if(st.top() == '<') st.pop();
            else st.push(i);
        }else st.push(i);
    }
    cout << (st.size() == 0 ? "Yes" : "No") << endl;
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