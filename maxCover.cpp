#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define fl(i,s,e) for(int i=s; i<=e; i++)
#define fr(i,e,s) for(int i=e; i>=s; i--)
#define all(x) x.begin(), x.end()
const ll mod = 998244353;
const ll inf = (ll)1e17;
// Practice Better -> Become Better
// By Harshdeep Singh

void solve() {

    ll n;
    cin >> n;

    ll x[n+1];
    fl (i,1,n) cin >> x[i];

    ll m;
    cin >> m;

    ll y[n+1];
    fl (i,1,n) cin >> y[i];

    unordered_map<ll, ll> X;
    unordered_map<ll, ll> Y;

    fl (i,1,n) {

        X[x[i]]++;
        Y[y[i]]++;

    }

    ll ans = 0;
    for (auto &v : X) {
        ans = max(ans, v.second);
    }    for (auto &v : Y) {
        ans = max(ans, v.second);
    }

    cout << ans;

}
 
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin); 
        freopen("output1.txt", "w", stdout);
    #endif
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll t = 1;
    cin >> t;
    fl(i, 1, t) {
        solve();
        cout << endl;
    }
 
    return 0;
}
