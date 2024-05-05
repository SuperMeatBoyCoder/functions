#include <iostream>
 
int MOD = 1e9 + 7;
using ll = long long;
using namespace std;

// return a ^ n mod m with time complexity O(log(n))
ll binpow(ll a, ll n, ll m=MOD) {
    ll res = 1;
    while (n != 0) {
        if (n % 2 == 1)
            res = res * a % m;
        a = a * a % m;
        n /= 2;
    }
    return res;
}
 
// find inverse as x ^ (p - 2), p must be a prime number
ll inv(ll x, ll p) {
    return binpow(x, p - 2);
}
 
int main() {
    cout << inv(-30, MOD);
    return 0;
}
 
