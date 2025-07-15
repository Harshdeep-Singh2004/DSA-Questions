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

// Max Heap (1 based indexing)

class MaxHeap {

private:
    ll n;
    vector<ll> arr;

public:
    MaxHeap() {
        n = 0;
        arr.resize(MAX+1, -1);
    }

    void insert(ll val) { // TC : O(log n)
        if (n == MAX) {
            cout << "Limit Reached";
            return;
        }

        n++;
        arr[n] = val;
        ll i = n;

        while (i>=2) {
            // i>=2 ensuring parent is atleast 1 and for i=1 (already a heap)
            ll p = i/2;
            if (arr[p] < arr[i]) {
                swap(arr[p], arr[i]);
                i = p;
            }
            else break;
        }

    }

    void heapify(ll i) { // TC : O(logn)

        while (i>=1) {
            ll l = 2*i, r = 2*i+1;
            ll L = i;

            if (l<=n && arr[l]>arr[L]) L=l;
            if (r<=n && arr[r]>arr[L]) L=r;

            if (L == i) break;

            swap(arr[L], arr[i]);
            i = L;
        }

    }

    void delRoot() { // TC : O(logn)
        if (n == 0) return;

        swap(arr[1], arr[n]);
        arr[n] = -1;
        n--;

        heapify(1);
    }

    void heapSort() { // TC : O(n x logn)
        if (n<=1) return;

        ll m = n;

        fr (i,m,2) {
            swap(arr[1], arr[n]);
            n--;
            heapify(1);
        }

        n=m;
    }

    void printHeap() { // TC : O(N)
        fl(i, 1, n) cout << arr[i] << ' ';
        cout << endl;
    }

    int getMax() { // TC : O(1)
        if (n==0) return -1;
        return arr[1];
    }

    void buildHeap(vector<ll> &val) { // Amortized TC : O(n)
        n = val.size();

        fl (i,1,n) arr[i] = val[i-1];

        fr (i,n/2,1) {
            heapify(i);
        }
    }

};


void solve() {

    // MaxHeap h;

    // vector<ll> values = {
    //     50, 20, 15, 40, 70, 90, 100, 30, 10, 80, 60, 55, 85, 25, 95
    // };

    // h.buildHeap(values);
    // h.heapSort();
    // h.printHeap();


    MaxHeap h;

    vector<ll> values = {
        50, 20, 15, 40, 70, 90, 100, 30, 10, 80, 60, 55, 85, 25, 95
    };

    cout << "Inserting values:\n";
    for (ll val : values) {
        h.insert(val);
        cout << val << " ";
    }
    cout << "\n\nHeap after insertions:\n";
    h.printHeap();

    cout << "\nDeleting root 5 times:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "Max = " << h.getMax() << "\n";
        h.delRoot();
        h.printHeap();
    }

    cout << "\nHeap before heapSort:\n";
    h.printHeap();

    cout << "\nSorted output using heapSort:\n";
    h.heapSort();
    h.printHeap();



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
        // cout << endl;
    }
 
    return 0;
}
