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
using ld = long double;
#define ldcout cout << fixed << setprecision(12)
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
ll INF = 2e9;
ll MOD = 1e9 + 7;
const ld PI = acos(-1.0);

vector<vector<int>> g;
vector<vector<int>> rev_g;
vector<int> colors;
vector<int> tin;
vector<int> tout;
vector<int> order;
vector<bool> used;
vector<bool> from_s;
vector <pair<int, int>> querys;
set <pair<int, int>> ans;
map <int, int> rev_colors;
vector<set<int>> new_g;
int t, c, n, m, s;


void dfs(int v) {
    from_s[v] = true;
    for (int u: g[v])
        if (!from_s[u])
            dfs(u);
}

void dfs1(int v) {
    used[v] = true;
    for (int u: g[v])
        if (!used[u])
            dfs1(u);
    order.push_back(v);
    tout[v] = t;
    t++;
}

void dfs2(int v, int c) {
    colors[v] = c;
    for (int u: rev_g[v])
        if (colors[u] == -1)
            dfs2(u, c);
}

void top_sort() {
    t = 0;
    for (int i = 0; i < n; i++)
        if (tout[i] == -1)
            dfs1(i);
    
    c = 0;
    reverse(all(order));
    for (int i : order)
        if (colors[i] == -1)
            dfs2(i, c++);
}
