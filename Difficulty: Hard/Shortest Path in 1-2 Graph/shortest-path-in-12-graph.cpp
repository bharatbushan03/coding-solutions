class Solution {
  public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {
        vector<vector<pair<int, int>>> adj(V);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // Since the graph is undirected
        }
        
        // Step 2: Min-heap priority queue to store {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Step 3: Distance array initialized to infinity
        vector<int> dist(V, 1e9);
        
        dist[src] = 0;
        pq.push({0, src});
        
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            
            // If we reached the destination, we can return the distance early
            if (u == dest) return d;
            
            // If a shorter distance to u has already been processed, skip
            if (d > dist[u]) continue;
            
            // Traverse neighbors
            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        
        // If destination is not reachable
        return dist[dest] == 1e9 ? -1 : dist[dest];
    }
};