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

void solve() {

    ll N,M;
    cin >> N >> M;

    vector<ll> A(N);
    vector<ll> B(N);

    fl(i,0,N-1) {
        cin >> A[i] >> B[i];
    }

    vector<vector<ll>> dp(N+1, vector<ll>(M+1, 0));

    fl (i,0,N) {
        fl(sum,0,M) {

            if (i==0) {
                dp[i][sum] = (sum == 0);
                continue;
            }

            bool up = (sum>=A[i-1] ? dp[i-1][sum-A[i-1]] : 0);
            bool down = (sum>=B[i-1] ? dp[i-1][sum-B[i-1]] : 0);

            if (up) {
                dp[i][sum] = 1;
            }
            else if (down) {
                dp[i][sum] = 2;
            }

        }
    }

    fl (i,0,N) {
        fl(sum,0,M) {
            cout << dp[i][sum] << " ";
        }
        cout << endl;
    }

    // If not possible to reach M
    if (dp[N][M] == 0) {
        cout << "NO";
        return;
    }

    // Backtrack to find the path
    cout << "YES\n";
    string path = "";
    ll sum = M;
    for (ll i = N; i >= 1; i--) {
        if (dp[i][sum] == 1) {
            path += 'A';
            sum -= A[i-1];
        } else if (dp[i][sum] == 2) {
            path += 'B';
            sum -= B[i-1];
        }
    }
    reverse(path.begin(), path.end());
    cout << path;

        
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
