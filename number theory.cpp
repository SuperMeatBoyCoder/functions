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
 
#define debug(x) cerr << __LINE__ << ": " << (#x) << " = " << x << endl;
//#define debug(x);
using ll = long long;
#define int long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
int INF = 2e9;
int MOD = 1e9 + 7;

ll mod;


ll binpow(ll a, ll n) {
    ll res = 1;
    while (n != 0) {
        if (n % 2 == 1)
            res = res * a % mod;
        a = a * a % mod;
        n /= 2;
    }
    return res;
}
 
ll inv(ll x) {
    return binpow(x, mod - 2);
}

ll add(int a, int b) {
    if (a + b >= mod) return a + b - mod;
    return a + b;
}

ll sub(int a, int b) {
    if (a < b) return a - b + mod;
    return a - b;
}

ll mul(int a, int b) {
    return a * b % mod;
}

ll divis(int a, int b) {
    return a * inv(b) % mod;
}

vector <int> extended_gcd(int x, int y) {
    int xy_gcd = gcd(x, y);
    int step_p = y / xy_gcd;
    int step_q = -x / xy_gcd;

    x /= xy_gcd;
    y /= xy_gcd;

    if (x == y)
        return {xy_gcd, 1, 0, step_p, step_q};

    else if (y == 1)
        return {xy_gcd, 1, -x + 1, step_p, step_q};

    vector <int> quotients;
    int temp, quotient;
    while (y > 0) {
        temp = y;
        quotient = x / y;
        y = x % y;
        x = temp;
        quotients.push_back(quotient);
    }
    quotients.pop_back();
    int p = 1;
    int q = -quotients.back();
    quotients.pop_back();
    while (!quotients.empty()) {
        p -= q * quotients.back();
        quotients.pop_back();
        swap(p, q);
    }
    return {xy_gcd, p, q, step_p, step_q};
}

//not tested
ll gcd_inv(ll x) {
    return extended_gcd(x, mod)[1];
}

void solve() {
  
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int _;
    _ = 1;
    cin >> _;
    while (_--)
        solve();
    return 0;
};
