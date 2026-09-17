#include <vector>
#include <deque>

using namespace std;

class Solution {
  public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {
        // Build adjacency list: {neighbor, cost}
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v, 0}); // Original direction: 0 cost
            adj[v].push_back({u, 1}); // Reversed direction: 1 cost
        }

        // Distance array initialized to infinity
        const int INF = 1e9;
        vector<int> dist(n + 1, INF);

        // 0-1 BFS setup
        deque<int> dq;
        dist[src] = 0;
        dq.push_front(src);

        while (!dq.empty()) {
            int u = dq.front();
            dq.pop_front();

            if (u == dst) {
                return dist[dst];
            }

            for (const auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;

                    // Push to front for 0-weight edges, back for 1-weight edges
                    if (weight == 0) {
                        dq.push_front(v);
                    } else {
                        dq.push_back(v);
                    }
                }
            }
        }

        return dist[dst] == INF ? -1 : dist[dst];
    }
};