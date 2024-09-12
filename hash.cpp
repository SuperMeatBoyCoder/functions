void hash_func(const ll P, const ll MOD, const string& s, vector<ll>& p_vec, vector<ll>& hash_pref) {
    int n = s.size();
    if (p_vec.size() < n + 1)
        p_vec.resize(n + 1);
    hash_pref.resize(n + 1);
    p_vec[0] = 1;
    ll now_P = P;
    for (int i = 1; i <= n; i++) {
        p_vec[i] = now_P;
        now_P = now_P * P % MOD;
    }
    hash_pref[0] = 0;
    for (int i = 1; i <= n; i++) {
        hash_pref[i] = (hash_pref[i - 1] + p_vec[i] * (s[i - 1] + 1)) % MOD;
    }
    //ll hash_substr = (hash_pref[j] - hash_pref[i] + MOD) * p_vec[h - i] % MOD;
}
