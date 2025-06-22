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

class Solution {
public:
    vector<vector<int>> lengthOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> dp(n, 1);
        int len = 0;

        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {

                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], 1+dp[j]);
                }

            }
            len = max(len, dp[i]);
        }

        queue<pair<pair<int,int>, vector<int>>> q;
        vector<vector<int>> ans;

        for (int i=0; i<n; i++) {
            if (dp[i] == len) {
                q.push({{i, len}, {nums[i]}});
            }
        }

        while (!q.empty()) {

            int L = q.size();

            while (L--) {

                auto x = q.front();
                q.pop();

                int i = x.first.first;
                int len = x.first.second;
                vector<int> vec = x.second;

                if (len == 1) {
                    ans.push_back(vec);
                    continue;
                }


                for (int j=0; j<i; j++) {

                    if (nums[i] > nums[j] && dp[j] == len-1) {
                        vec.push_back(nums[j]);
                        q.push({ {j, len-1}, vec });
                        vec.pop_back();
                    }

                }

            }

        }

        return ans;

    }

};

void solve() {  
    
    Solution obj;

    vector<int> nums = {10,9,2,5,3,7,101,18};

    vector<vector<int>> ans = obj.lengthOfLIS(nums);

    for (auto &vec : ans) {
        
        for (auto &x : vec) {
            cout << x << " ";
        }

        cout << endl;

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
        cout << endl;
    }
 
    return 0;
}
