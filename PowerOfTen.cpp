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
    BinaryLifting(ll n, vector<ll> &parent, vector<ll> &level) {
        this->parent = parent;
        this->level = level;
        dp.resize(21, vector<ll>(n+1));
        fillDP(this->parent, dp);
    }

    ll lca(ll u, ll v) {
        ll U = level[u];
        ll V = level[v];

        if (U>V) return lca(v, u);
        ll D = V-U;

        fr(i,20,0) {
            ll bit = D&(1<<i);
            if (bit&1) v = dp[i][v];
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

ll factor(ll x, ll k) {
    ll cnt = 0;
    while (x%k==0) {
        cnt++;
        x/=k;
    }
    return cnt;
}

void solve() {

    ll n, query;
    cin >> n >> query;

    vector<pair<ll,ll>> child[n+1];

    fl(i,1,n-1) {
        ll a, b, c;
        cin >> a >> b >> c;

        child[a].push_back({b, c});
    }

    vector<ll> parent(n+1),  level(n+1);
    parent[1] = 1, level[1] = 1;

    ll two[n+1], five[n+1];
    two[1] = 0;
    five[1] = 0;

    // Level Order Traversal
    queue<ll> q; // node, weight
    q.push(1);

    while (!q.empty()) {

        ll u = q.front();
        q.pop();

        for (auto &it : child[u]) {
            ll v = it.first, w = it.second;
            two[v] = two[u] + factor(w,2);
            five[v] = five[u] + factor(w,5);

            parent[v] = u;
            level[v] = level[u]+1;

            q.push(v);
        }

    }

    BinaryLifting BL(n, parent, level);

    while (query--) {

        ll u,v;
        cin >> u >> v;

        ll com = BL.lca(u,v);

        ll twos = two[u] + two[v] - 2*two[com]; 
        ll fives = five[u] + five[v] - 2*five[com];

        cout << min(twos, fives);

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
        cout << "Case " << i << ":" << endl;
        solve();
        cout << endl;
    }
 
    return 0;
}
