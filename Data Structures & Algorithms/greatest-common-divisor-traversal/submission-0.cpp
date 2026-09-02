class DS {
public: 
    vector<int> parent, rank;
    DS(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int u) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    void joint(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return;
        if (rank[pv] < rank[pu]) parent[pv] = pu;
        else if (rank[pu] < rank[pv]) parent[pu] = pv;
        else { parent[pv] = pu; rank[pu]++; }
    }
};

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;

        unordered_map<int, int> factor_to_idx;
        DS ds(n);

        for (int i = 0; i < n; i++) {
            int val = nums[i];
            if (val == 1) return false;

            // Find all prime factors of nums[i]
            for (int factor = 2; factor * factor <= val; factor++) {
                if (val % factor == 0) {
                    if (factor_to_idx.count(factor)) {
                        ds.joint(i, factor_to_idx[factor]);
                    } else {
                        factor_to_idx[factor] = i;
                    }
                    while (val % factor == 0) val /= factor;
                }
            }
            // If remaining val > 1, it is a prime factor itself
            if (val > 1) {
                if (factor_to_idx.count(val)) {
                    ds.joint(i, factor_to_idx[val]);
                } else {
                    factor_to_idx[val] = i;
                }
            }
        }

        // Check if all indices belong to the same connected component
        int root = ds.find(0);
        for (int i = 1; i < n; i++) {
            if (ds.find(i) != root) return false;
        }
        return true;
    }
};