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

void solve() {
    // --- Input Reading ---
    int n, m, distanceLimit;
    cin >> n >> m;
    
    vector<vector<int>> packages(n, vector<int>(m));
    fl(i, 0, n - 1) {
        fl(j, 0, m - 1) {
            cin >> packages[i][j];
        }
    }
    cin >> distanceLimit;

    // --- Algorithm Implementation ---

    // 1. Multi-source BFS to mark all breached cells
    vector<vector<bool>> breached(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    
    // Initialize the queue with all cells that are security breaches (value 0)
    fl(i, 0, n - 1) {
        fl(j, 0, m - 1) {
            if (packages[i][j] == 0) {
                breached[i][j] = true;
                q.push({i, j});
            }
        }
    }

    // Directions for BFS (up, down, left, right)
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int currentDistance = 0;

    // Propagate breaches up to distanceLimit
    while (!q.empty() && currentDistance < distanceLimit) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; ++i) {
            auto t = q.front();
            int x = t.first, y = t.second;
            q.pop();

            fl(k, 0, 3) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !breached[nx][ny]) {
                    breached[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        currentDistance++;
    }

    // If start or end point is breached, no path is possible
    if (breached[0][0] || breached[n-1][m-1]) {
        cout << 0 << "\n";
        return;
    }

    // 2. Dynamic Programming to count paths
    // dp[i][j] = number of ways to reach cell (i, j)
    vector<vector<ll>> dp(n, vector<ll>(m, 0));

    // Base case: There's one way to be at the start cell
    dp[0][0] = 1;

    fl(i, 0, n - 1) {
        fl(j, 0, m - 1) {
            if (breached[i][j]) {
                continue;
            }
            // Path can come from the top cell (i-1, j)
            if (i > 0) {
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
            }
            // Path can come from the left cell (i, j-1)
            if (j > 0) {
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;
            }
        }
    }

    cout << dp[n-1][m-1] << "\n";
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
