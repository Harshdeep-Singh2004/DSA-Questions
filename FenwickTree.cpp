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
ll a[1000], BIT[1000], n;
// Consider 1 based indexing


void update(ll i, ll delta) {
    for (; i<=n ; i+=i&-i) BIT[i] += delta;
}

ll query(ll i) {
    if (i == 0) return 0;

    ll ans = 0;
    for (; i>0; i-=i&-i) ans += BIT[i];
    return ans;
} 

ll sum(ll l, ll r) { // inclusive sum from L to R
    return query(r) - query(l-1);
}


void solve() {

    cin >> n;
    fl(i,1,n) {
        cin >> a[i];
        update(i, a[i]);
    }

    cout << sum(1,3);

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
