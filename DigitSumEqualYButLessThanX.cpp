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
ll x,y;
ll n;
ll dp[1001][9001][2];
string s;

ll get(ll i, ll sum, bool t) {

    if (sum < 0) return 0;
    if (i==n) return (sum==0);

    if (dp[i][sum][t] != -1) return dp[i][sum][t];

    ll cnt = 0;
    ll x = (t ? s[i]-'0' : 9);

    // 0....i-1 pref is same as of s[0 ... i-1]
    fl (j,0,x) {
        cnt += get(i+1,sum-j, t && j==x);
    }

    return dp[i][sum][t] = cnt;

}

void solve() {

    cin >> x >> y;

    s = to_string(x);

    n = s.size();

    memset(dp, -1, sizeof(dp));

    cout << get(0,y,1);

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
