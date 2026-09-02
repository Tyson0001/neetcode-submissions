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
        int n=nums.size();
        if(n==1) return true;
        unordered_map<int,int>factor_idx;
        DS ds(n);
        for(int i=0;i<n;i++){
            int num=nums[i];
            if(num==1) return false;
            for(int factor =2 ;factor*factor<=num;factor++){
                if(num%factor == 0){
                    if(factor_idx.count(factor)){
                        ds.joint(factor_idx[factor],i);
                    }else{
                        factor_idx[factor]=i;
                    }
                    while(num%factor  ==0) num/=factor;
                }
            }
            if(num>1){
                if(factor_idx.count(num)){
                    ds.joint(factor_idx[num],i);
                }else factor_idx[num]=i;
            }
        }
        int idx=ds.find(0);
        for(int i=1;i<n;i++){
            if(ds.find(i)!=idx) return false;
        }
        return true;
    }
};