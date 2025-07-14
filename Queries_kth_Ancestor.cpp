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
const ll N = 1e5+100;
const ll mod = 998244353;
const ll inf = (ll)1e16;
// Practice Better -> Become Better
// By Harshdeep Singh
 
// BINARY LIFTING
 
class TreeAncestor {
private:
    vector<vector<ll>> dp;
public:
    // Preprocessing TC : O(n x logn), SC : O(n x logn) 
    TreeAncestor(ll n, vector<ll>& parent) {
 
        dp.resize(21, vector<ll>(n, 0));
        // Base Case
        fl (j,0,n-1) {
            dp[0][j] = parent[j];
        }
        // Iterative DP
        fl (i,1,20) {
            fl (j,0,n-1) {
                ll F = dp[i-1][j];
                if (F == -1) {
                    dp[i][j] = -1;
                    continue;
                }
                ll S = dp[i-1][F];
                dp[i][j] = S;
            }
        }
 
    }
    
    // Find TC - O(logn), SC - O(1)
    ll getKthAncestor(ll node, ll k) {
 
        ll par = node;

        fr (i,20,0) {
            ll bit = k & (1<<i);
            if (bit == 1 && par != -1) par = dp[i][par];
        }
        
        return par;
 
    }
};
 
 
void solve() {
 
    ll n, q;
    cin >> n >> q;
 
    vector<ll> parent(n);
    parent[0] = -1;
    fl (i,1,n-1) {
        cin >> parent[i];
        parent[i]--;
    }
 
 
    TreeAncestor TA(n, parent);
 
    while (q--) {
 
        ll x, k;
        cin >> x >> k;
        x--;
 
        ll ans = TA.getKthAncestor(x,k);
        cout << (ans == -1 ? ans : ans+1) << endl;  
 
    }
        
} 
 
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
    ll t=1;
    // cin >> t;
    while (t--) {
        solve();
        // cout << endl;
    }
 
    return 0;
}
