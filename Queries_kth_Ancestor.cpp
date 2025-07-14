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

// Binary lifting : Ye method Binary or Generic Trees ke liye use kiya jaata hai jab LCA or Kth Ancestor par operations perform karne hote hai.
// Queries di jaati hai

// Binary Lifting is a technique used to efficiently answer ancestor-related queries in a tree, especially useful for problems like:
// Finding the k-th ancestor of a node.
// Finding Lowest Common Ancestor (LCA) of two nodes.


// Preprocessing  TC : O(n x logn) | SC : O(n x logn)
// Kth Ancestor TC : O(logn) | SC : O(1)
// Overall with Queries : TC : O(n x logn) + O(q x logn) | SC : O(n x logn)

// Range of n : 1<=n<=1e6 | 1<=q<=1e6

class TreeAncestor {
private:
    vector<vector<ll>> dp;
public:
    // Preprocessing TC : O(n x logn), SC : O(n x logn) 
    TreeAncestor(ll n, vector<ll>& parent) {
 
        dp.resize(32, vector<ll>(n, 0));
        // Base Case
        fl (j,0,n-1) {
            dp[0][j] = parent[j];
        }
        // Iterative DP
        fl (i,1,31) {
            fl (j,0,n-1) {
                ll F = dp[i-1][j];
                if (F == -1) dp[i][j] = -1;
                else dp[i][j] = dp[i-1][F];
            }
        }
 
    }
    
    // Find TC - O(logn), SC - O(1)
    ll getKthAncestor(ll node, ll k) {
 
        ll par = node;

        fr (i,31,0) {
            ll bit = (k<<i) & 1;
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
