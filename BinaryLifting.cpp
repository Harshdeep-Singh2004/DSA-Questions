// BINARY LIFTING

class TreeAncestor {
private:
    // dp[i][j] - (1<<i)th ancestor of jth node
    vector<vector<int>> dp;

public:
    // Preprocessing TC : O(n x logn), SC : O(n x logn) 
    TreeAncestor(int n, vector<int>& parent) {

        dp.resize(17, vector<int>(n, 0));

        // Base Case
        for (int j=0; j<n; j++) {
            dp[0][j] = parent[j];
        }

        // Iterative DP
        for (int i=1; i<16; i++) {
            for (int j=0; j<n; j++) {

                int F = dp[i-1][j];
                if (F == -1) {
                    dp[i][j] = -1;
                    continue;
                }
                int S = dp[i-1][F];
                if (S == -1) {
                    dp[i][j] = -1;
                    continue;
                }
                dp[i][j] = S;

            }
        }

    }
    
    // Find TC - O(logn), SC - O(1)
    int getKthAncestor(int node, int k) {
        
        int par = node;
        int i = 0;

        while (k) {
            
            int bit = k&1;

            if (bit == 1) {
                par = dp[i][par];
                if (par == -1) break;
            }

            i++;
            k >>= 1;

        }

        return par;

    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
