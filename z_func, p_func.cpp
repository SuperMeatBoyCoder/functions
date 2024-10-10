vector<int> z_func(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r)
            z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            z[i]++;
        }
        if (i + z[i] > r) {
            l = i, r = z[i] + i;
        }
    }
    return z;
}

vector<int> p_func(string s) {
    int n = s.size();
    vector<int> p(n + 1);
    p[0] = -1;
    for (int i = 1; i <= n; i++) {
        int k = p[i - 1];
        while (k != -1 && s[k] != s[i - 1]) {
            k = p[k];
        }
        p[i] = ++k;
    }
    return p;
}
