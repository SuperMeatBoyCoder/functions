class Hash {
private:
    const ll P, HMOD;
    vector<ll> p_vec, hash_pref;
public:
    Hash(const ll _P, const ll _MOD, const string s) : P(_P), HMOD(_MOD) {
        int n = s.size();
        p_vec.resize(n + 1);
        hash_pref.resize(n + 1);
        p_vec[0] = 1;
        hash_pref[0] = 0;
        ll now_P = P;
        for (int i = 1; i <= n; i++) {
            p_vec[i] = now_P;
            now_P = now_P * P % HMOD;
            hash_pref[i] = (hash_pref[i - 1] * P + s[i - 1]) % HMOD;
        }
    }

    ll hsubstr(int L, int R) {
        // [L, R)
        return ((hash_pref[R] - hash_pref[L] * p_vec[R - L]) % HMOD + HMOD) % HMOD;
    }
};
