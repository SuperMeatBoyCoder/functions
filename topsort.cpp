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
vector <int> deq;
bool cycle = false;
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

void components_coloring() {
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


void paint(int v) {
    colors[v] = 1;
    for (int u : g[v]) {
        if (colors[u] == 1)
            cycle = true;
        if (colors[u] == -1)
            paint(u);
    }
    colors[v] = 2;
}

void topsort() {
    for (int i = 0; i < n; i++)
        if (colors[i] == -1)
            paint(i);
    if (cycle) {
        cout << "NO";
        return;
    }

    if (!cycle) {
        queue<int> q;
        vector <int> res;
        res.reserve(n);
        for (int i = 0; i < n; i++) {
            if (deq[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int v = q.front();
            res.push_back(v + 1);
            q.pop();
            for (int u: g[v]) {
                deq[u]--;
                if (deq[u] == 0)
                    q.push(u);
            }
        }
        reverse(all(res));
        for (int i = 0; i < n; i++) cout << res[i] << ' ';
    }
}

void build() {
    int n, m;
    cin >> n;
    colors.resize(n, -1);
    deq.resize(n, 0);
    g.resize(n);
    colors.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; 
        a--; b--;
        if (a != b) {
            g[a].push_back(b);
            deq[b]++;
        }
    }
}
