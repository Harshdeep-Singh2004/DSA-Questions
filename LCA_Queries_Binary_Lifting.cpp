#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define fl(i,s,e) for(int i=s; i<=e; i++)
#define flg(i,s,e,g) for(int i=s; i<=e; i+=g) // gap
#define fr(i,e,s) for(int i=e; i>=s; i--)
#define all(x) x.begin(), x.end()
#define lowerBit(x) (x)&(-x)
#define parity(x) (x&1)
const ll mod = 1e9+7;
const ll inf = (ll)1e18;
// Practice Better -> Become Better
// By Harshdeep Singh

class BinaryLifting {
private:
    vector<ll> parent;
    vector<ll> level;
    vector<vector<ll>> dp;

    void dfs(ll u, vector<ll>& parent, vector<ll>& level, vector<ll> child[]) {
        for (auto &v: child[u]) {
            parent[v] = u;
            level[v] = level[u]+1;
            dfs(v, parent, level, child);
        }
    }

    void pre_process(vector<ll> &parent, vector<vector<ll>> &dp) {
        ll n = parent.size()-1;
        fl (j,1,n) dp[0][j] = parent[j];

        fl (i,1,31) {
            fl (j,1,n) {
                ll F = dp[i-1][j];
                dp[i][j] = dp[i-1][F];
            }
        }
    }

public:
    BinaryLifting(ll n, vector<ll> child[]) {
        parent.resize(n+1);
        level.resize(n+1);
        dp.resize(32, vector<ll> (n+1));

        parent[1] = 1;
        level[1] = 1;

        dfs(1, parent, level, child);
        pre_process(parent, dp);
    }

    ll lca(ll u, ll v) {

        ll U = level[u];
        ll V = level[v];

        if (U > V) return lca(v, u);
        ll D = V-U;

        fr(i,31,0) {
            ll bit = (D>>i)&1;
            if (bit == 1) v = dp[i][v];
        }
        if (u==v) return u;

        fr(i,31,0) {
            ll pu = dp[i][u];
            ll pv = dp[i][v];

            if (pu != pv) {
                u = pu;
                v = pv;
            }
        }

        u = parent[u];
        return u;

    }

};


void solve() {

    ll n,q;
    cin >> n >> q;

    vector<ll> child[n+1];

    fl (i,2,n) {
        ll e;
        cin >> e;
        child[e].push_back(i);
    }

    BinaryLifting BL(n, child);

    while (q--) {

        ll a,b;
        cin >> a >> b;

        cout << BL.lca(a,b) << endl;

    }

}   
 
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
    ll t=1;
    // cin >> t;
    fl(i,1,t) {
        solve();
        // cout << endl;
    }
 
    return 0;
}
