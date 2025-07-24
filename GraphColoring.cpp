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
const ll MAX = 1e6;
// Practice Better -> Become Better
// By Harshdeep Singh

// Helper function to calculate permutations P(n, k) % mod
ll perm(ll n, ll k) {
    if (k < 0 || k > n) {
        return 0;
    }
    ll res = 1;
    for (int i = 0; i < k; ++i) {
        res = (res * (n - i)) % mod;
    }
    return res;
}

void solve() {
    int n; // Number of cities
    ll m;  // Number of monument types
    cin >> n >> m;

    // Edge case: a single city can have any of the m monuments.
    if (n == 1) {
        cout << m % mod << endl;
        return;
    }

    // 1. Build adjacency list and compute degrees for each city.
    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v); // Using 'pb' macro from template
        adj[v].pb(u);
        degree[u]++;
        degree[v]++;
    }

    // 2. Feasibility Check: Check if a valid assignment is possible.
    // For any node u, we need degree[u] + 1 unique colors.
    for (int i = 1; i <= n; ++i) {
        if (degree[i] + 1 > m) {
            cout << 0 << endl;
            return;
        }
    }

    // 3. Calculate ways using a Breadth-First Search (BFS) traversal.
    ll ans = 1;
    vector<bool> visited(n + 1, false);
    queue<int> q;
    
    // Choose city 1 as the arbitrary root of the tree.
    int root = 1;
    q.push(root);
    visited[root] = true;

    // Calculate initial ways for the root and its direct neighbors.
    // - m ways to color the root itself.
    // - P(m-1, degree[root]) ways to color its neighbors.
    ans = (m * perm(m - 1, degree[root])) % mod;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                // v is a child of u. We are assigning colors to v's children.
                // Number of v's children = degree[v] - 1.
                // Available colors = m - 2 (excluding colors of parent u and v itself).
                ll term = perm(m - 2, degree[v] - 1);
                ans = (ans * term) % mod;
                q.push(v);
            }
        }
    }
    
    cout << ans << endl;
}   
 
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    // cin >> t; // Uncomment if there are multiple test cases
    fl(i,1,t) {
        solve();
    }
 
    return 0;
}
