// Q1. A string is said to be k-special if, for every pair of distinct characters in the string, the absolute difference of their frequencies differs by at most k. Formally, if a character i occurs freq_i times in the string, and the character j occurs freq_j times, then if |freq_i-freq_j| <= k, for every pair of characters i and j, then the string is said to be k-special.

// Given a string word of length n and an integer k the task is to determine the minimum number of characters to be removed from word so that it becomes a k-special string.

// 1<=n<=1e5
// 0<=k<=1e5

// Example
// word = "solidandliquid" and k = 1.
// ans = 2

// Word = “abccccdddd” and k = 1
// Ans = 2

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

void solve() {  
    
    string s;
    cin >> s;

    int k;
    cin >> k;

    int n = s.size();

    vector<int> Alpha(26, 0);

    for (int i=0; i<n; i++) {
        Alpha[ s[i]-'a' ]++;
    }

    vector<int> arr;
    for (int i=0; i<=25; i++) {
        int cnt = Alpha[i];

        if (cnt) {
            arr.push_back(cnt);
        }
    }

    sort(all(arr));

    for (auto &x: arr) {
        cout << x << " ";
    }



    int i=0, m=arr.size();
    int cnt1 = 0, cnt2 = 0;

    while (i<m) {
        if (arr[m-1]-arr[i] > k) cnt1 += arr[i];
        else break;
        i++; 
    }

    i = m-1;
    while (i>=0) {
        if (arr[i]-arr[0] > k) cnt2 += (arr[i] - k - arr[0]);
        else break;
        i--; 
    }

    cout << min(cnt1, cnt2);
    
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
