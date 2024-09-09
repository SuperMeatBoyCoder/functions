#include <bits/stdc++.h>
#include <iterator>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
template<class T> using ordered_set_descending = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset_descending = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;
using ld = long double;
#define ldcout cout << fixed << setprecision(12)
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
const ll INF = 2e9;
const ll MOD = 1e9 + 7;
const ld PI = acos(-1.0);

template<class T>
void exit_print(T x) {
    cout << x << '\n';
    exit(0);
}

template <class T>
bool greater_func(T a, T b) {
    return a > b;
}

void solve() {

}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
};
