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
    vector<ll> sum;
    vector<vector<ll>> dp;

    void dfs(ll u, vector<ll> adj[], vector<ll> &parent, vector<ll> &level, vector<ll> &sum) {

        for (auto &v : adj[u]) {
            parent[v] = u;
            level[v] = level[u]+1;

            dfs(v, adj, parent, level, sum);
            sum[u] += sum[v];
        }

    }

    void preProcess(vector<ll> &parent, vector<vector<ll>> &dp) {

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
    BinaryLifting(ll n, vector<ll> &a, vector<ll> adj[]) {

        parent.resize(n+1);
        level.resize(n+1);
        sum.resize(n+1);
        dp.resize(32, vector<ll>(n+1));

        parent[1] = 1;
        level[1] = 1;

        fl(i,1,n) sum[i] = a[i];
        dfs(1, adj, parent, level, sum);
        preProcess(parent, dp);

    }

    ll LCA(ll u, ll v) {

        ll U = level[u];
        ll V = level[v];

        if (U > V) return LCA(v, u);

        ll D = V-U;

        fr (i,31,0) {
            ll bit = (D>>i)&1;
            if (bit) v = dp[i][v];
        }

        if (v == u) return v;

        fr (i,31,0) {
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

    ll add(ll u) {
        return sum[u];
    }

};

void solve() {

    ll n = 7;
    vector<ll> a = {-1, 20, 40, 30, 100, 10, 50, 10};
    
    vector<ll> adj[n+1];
    adj[1] = {7,3};
    adj[2] = {4,5};
    adj[3] = {6};
    adj[4] = {};
    adj[5] = {};
    adj[6] = {};
    adj[7] = {2};

    BinaryLifting W(n, a, adj);

    ll u = 7;
    ll v = 6;
    ll x = 3;

    ll UV = W.LCA(u,v);
    ll UX = W.LCA(u,x);
    ll VX = W.LCA(v,x);

    fl (i,1,n) {
        cout << W.add(i) << " ";
    }
    cout << endl;

    ll ans = 0;

    if (UV == u || UV == v || x == UV) ans = W.add(x);
    else if (UX == x && UV == VX) ans = W.add(x) - W.add(u) + W.add(v);
    else if (VX == x && UV == UX) ans = W.add(x) - W.add(v) + W.add(u);
    else ans = W.add(x);

    cout << ans;


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
        cout << endl;
    }
 
    return 0;
}
