#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define fl(i,s,e) for(int i=s; i<=e; i++)
#define fr(i,e,s) for(int i=e; i>=s; i--)
#define all(x) x.begin(), x.end()
const ll MOD = 1e9+7;
const ll inf = (ll)1e17;

// Practice Better -> Become Better
// By Harshdeep Singh

ll power(ll base, ll exp) {
    ll ans = 1;
    base %= MOD;
    while (exp) {
        if (exp & 1) ans = (ans * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return ans;
}

ll inverseMod(ll a) {
    return power(a, MOD - 2);
}

ll nCr(ll n, ll r, vector<ll> &fact, vector<ll> &invFact) {
    if (r > n) return 0;
    ll ans = fact[n];
    ans = (ans * invFact[r]) % MOD;
    ans = (ans * invFact[n - r]) % MOD;
    return ans;
}

void solve() {
    ll n;
    cin >> n;
    ll m, r;
    cin >> m >> r;

    vector<ll> fact(n + 1);
    fact[0] = 1;
    fl(i, 1, n) fact[i] = (fact[i - 1] * i) % MOD;

    vector<ll> invFact(n + 1);
    invFact[n] = inverseMod(fact[n]);
    fr(i, n-1, 0) invFact[i] = ((i+1) * (invFact[i+1])) % MOD;

    cout << nCr(m, r, fact, invFact);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    // cin >> t;
    fl(i, 1, t) {
        solve();
        cout << '\n';
    }
    return 0;
}
