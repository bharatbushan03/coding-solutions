#include <vector>
#include <queue>
#include <algorithm>

class Solution {
private:
    // Helper function to find the farthest node and its distance from a given start node
    std::pair<int, int> getFarthestNode(int startNode, int n, const std::vector<std::vector<int>>& adj) {
        std::vector<int> dist(n + 1, -1);
        std::queue<int> q;

        q.push(startNode);
        dist[startNode] = 0;

        int maxDist = 0;
        int farthestNode = startNode;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            if (dist[u] > maxDist) {
                maxDist = dist[u];
                farthestNode = u;
            }

            // adj is 0-indexed where adj[i] represents connections for house (i + 1)
            for (int v : adj[u - 1]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return {farthestNode, maxDist};
    }

public:
    int partyHouse(std::vector<std::vector<int>> &adj) {
        int n = adj.size();
        if (n <= 1) return 0;

        // 1. Find one endpoint of the diameter starting from node 1
        auto [nodeA, _] = getFarthestNode(1, n, adj);

        // 2. Find the other endpoint and the tree's total diameter
        auto [nodeB, diameter] = getFarthestNode(nodeA, n, adj);

        // 3. Minimum possible distance to the farthest node is ceil(diameter / 2)
        return (diameter + 1) / 2;
    }
};