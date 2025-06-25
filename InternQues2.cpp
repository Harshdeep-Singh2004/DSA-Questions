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
const ll inf = (ll)1e18;
// Practice Better -> Become Better
ll n,d;
vector<ll> start;


// Q2. A set of n integer ranges (both ends inclusive) of d length each is given. The starting point of these ranges is given in an array starts. So the ith range (starting with zero index) consists of integers from starts[i] to starts[i] + d. One integer each is to be chosen from all of the ranges, subject to the condition that the difference between any pair of chosen integers is at least dist.

// Given the starting points of the ranges, in an array starts, and the length d of each range, the task is to determine the maximum possible value of dist such that it is possible to choose an integer from each of the ranges satisfying the above condition.

// 1<=n<=1e5
// 0<=d<=1e14
// 1<=starts[i]<=1e14


bool good(ll dist) {

    ll prev = start[0];

    fl (i,1,n-1) {

        ll curr = prev + dist;
        if (curr > start[i]+d) return 0;
        prev = max(curr, start[i]);
        
    }

    return 1;
}

void solve() {  
        
    cin >> n >> d;
    start.resize(n);

    fl (i,0,n-1) cin >> start[i];

    sort(all(start));

    ll s=0;
    ll e=start[n-1]-start[0]+d;

    ll ans = 0;

    while (s <= e) {
        ll m = s+(e-s)/2;
        if (good(m)) {
            ans = m;
            s = m+1;
        }
        else e = m-1;
    }

    cout << ans;
    
} 
 
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input1.txt", "r", stdin);
        freopen("output1.txt", "w", stdout);
    #endif
    ll t=1;
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }
 
    return 0;
}
