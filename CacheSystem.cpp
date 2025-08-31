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
ll n,m;
vector<ll> requests;

bool good(ll T) {

    ll extra = 0;
    ll cap = 0;

    fl (i,1,n) {

        if (requests[i] > T) {
            extra += (requests[i] - T);
        }
        else {
            cap += (T - requests[i])/2;
        }

    }

    return (cap >= extra);

}
 
void solve() {

    cin >> n >> m;
    // n -> servers
    // m -> requests

    requests.resize(n+1, 0);

    fl (i,1,m) {
        ll x;
        cin >> x; // x is the server that handles the ith request
        requests[x]++;
    }

    // request[i] - how many request did the server i recieved
    ll s = 0;
    ll e = 2*m+1;
    ll ans = -1;

    while (s<=e) {
        ll mid = s + (e-s)/2;

        if (good(mid)) {
            ans = mid;
            e = mid-1;
        }
        else s = mid+1;

    } 

    cout << (ans == -1 ? inf : ans);

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
