using P = pair<int,int>;
using T = vector<int>;

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        
        vector<P> adj[V];
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
            
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        priority_queue<T, vector<T>, greater<T>> pq; // {w, u, v}
        vector<int> vis(V,0);
        
        vis[0]=1;
        for (auto &e:adj[0]) {
            int v = e.first;
            int w = e.second;
            
            pq.push({w, 0, v});
        }
        
        int mst_weight = 0;
        vector<P> mst_edges;
        
        while (!pq.empty()) {
            
            auto x = pq.top();
            pq.pop();
            
            int u = x[1];
            int v = x[2];
            int w = x[0];
            
            // This represent, this edge was previously added, but now while incrementally making mst, we have found some
            // unique path from u to v, so do not include this edge, it will create a cycle
            // more simply, we have found some other vertex u from where the edge to v is cheaper than the current vertex u
            if (vis[v]) continue;
            
            vis[v]=1;
            mst_weight += w;
            mst_edges.push_back({u,v});
            
            for (auto &e:adj[v]) {
                int vert = e.first;
                int wt = e.second;
                
                // This line make sure, when adding edges of new vertex while incrementally making the mst one-by-one node
                // adding edge from this new vertex(v) does not include that edge which make a cycle, basically ignore the
                // edges that has v on one side and other vertex that is in current mst(subset of mst)
                if (!vis[vert]) pq.push({wt, v, vert});
            }
            
        }
        
        return mst_weight;
        
    }
};
