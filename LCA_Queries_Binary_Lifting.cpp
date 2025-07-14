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

    void dfs(ll u, vector<ll> child[]) {

        for (auto &v: child[u]) {
            parent[v] = u;
            level[v] = level[u]+1;
            dfs(v, child);
        }

    }

    void fillDP(vector<ll> &parent, vector<vector<ll>> &dp) {
        ll n = parent.size()-1;

        fl(j,1,n) dp[0][j] = parent[j];

        fl(i,1,20) {
            fl(j,1,n) {
                ll F = dp[i-1][j];
                ll S = dp[i-1][F];
                dp[i][j] = S;
            }
        }

    }

public:
    BinaryLifting(ll n, vector<ll> child[]) {
        parent.resize(n+1);
        level.resize(n+1);
        dp.resize(21, vector<ll>(n+1));

        parent[1] = 1;
        level[1] = 1;

        dfs(1, child);
        fillDP(parent, dp);
    }

    ll lca(ll u, ll v) {
        ll U = level[u];
        ll V = level[v];

        if (U>V) return lca(v, u);
        // u is lower in depth (upar hai)
        ll D = V-U;
        ll i = 0;
        while (D) {
            if (D&1) v = dp[i][v];
            i++;
            D >>= 1;
        }

        if (v==u) return u;

        fr(i,20,0) {
            ll up = dp[i][u];
            ll vp = dp[i][v];

            if (up != vp) {
                v = vp;
                u = up;
            }
        }

        u = parent[u];
        return u;

    }

};

void solve() {

    ll n;
    cin >> n;
    vector<ll> child[n+1];

    fl (u,1,n) {
        ll M;
        cin >> M;

        while (M--) {
            ll v;
            cin >> v;
            child[u].push_back(v);
        }
    }

    ll q;
    cin >> q;

    BinaryLifting bf(n, child);

    while (q--) {
        ll v,w;
        cin >> v >> w;

        cout << bf.lca(v,w) << endl;
    }

} 
 
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
    ll t=1;
    cin >> t;
    fl(i,1,t) {
        cout << "Case " << i << ":" << endl;
        solve();
        // cout << endl;
    }
 
    return 0;
}
