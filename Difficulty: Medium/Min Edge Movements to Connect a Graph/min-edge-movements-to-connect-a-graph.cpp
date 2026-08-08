// User function Template for C++

class Disjoint {
    vector<int> rank, parent;
    int V;
public:
    Disjoint(int V) {
        this->V = V;
        rank.resize(V, 0);
        parent.resize(V);
        
        for (int i=0; i<V; i++) {
            parent[i] = i;
        }
    }

    int UltimateParent(int u) {
        if (parent[u] == u) return u;
        
        return parent[u] = UltimateParent(parent[u]);
    }

    bool UnionByRank(int u, int v) {
        int up_u = UltimateParent(u);
        int up_v = UltimateParent(v);

        if (up_u == up_v) return false;

        if (rank[up_u] > rank[up_v]) {
            parent[up_v] = up_u;
        }
        else if (rank[up_u] < rank[up_v]) {
            parent[up_u] = up_v;
        }
        else {
            parent[up_u] = up_v;
            rank[up_v]++;
        }
        return true;
    }
    int Check() {
        int ans = 0;
        for (int i=0; i<V; i++) {
            if (parent[i] == i) ans++;
        }
        
        return ans;
    }
};
class Solution {
  public:
    int minEdgesReq(int n, vector<vector<int>>& edges) {
        if (edges.size() < n-1) return -1;
        Disjoint ds(n);
        for (auto edge : edges) {
            ds.UnionByRank(edge[0], edge[1]);
        }
        
        
        return ds.Check() - 1;
    }
};