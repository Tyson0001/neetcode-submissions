class DS{
public:
    vector<int>parent;
    vector<int>rank;
    DS(int n){
        parent.resize(n,0);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int u){
        if(u==parent[u]) return parent[u];
        return parent[u]=find(parent[u]);
    }
    void joint(int u ,int v){
        int pu=find(u), pv=find(v);
        if(pu==pv) return ;
        if(rank[pu]<rank[pv]) parent[pu]=pv;
        else if(rank[pv]<rank[pu]) parent[pv]=pu;
        else parent[pv]=pu,rank[pu]++;
    }

};

class Solution {
public:
    int krushal(vector<vector<int>>&edges,int n, int skip ,int force){
        DS ds(n);
        int cnt=0;
        int wt=0;
        if(force!=-1){
           if(ds.find(edges[force][0]) !=ds.find(edges[force][1])){
             ds.joint(edges[force][0],edges[force][1]);
             wt+=edges[force][2];
             cnt++;
             
            }
        } 
        int m=edges.size();
        for(int i=0;i<m;i++){
            auto e=edges[i];
            if(i==skip) continue;
            if(i==force) continue;
            if(ds.find(e[0])!=ds.find(e[1])){
                ds.joint(e[0],e[1]);
                wt+=e[2];
                cnt++;
            }
        }
        if(cnt!=n-1) return 1e9;
        return wt;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) { 
        int m=edges.size();
        for(int i=0;i<m;i++){
           edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),[](auto &a , auto &b){
           return a[2]<b[2];
        });
        int org=krushal(edges,n,-1,-1);
        vector<int>critical ;
        vector<int>non_critical;
        for(int i=0;i<m;i++){
            int test=krushal(edges,n,i,-1);
            if(test==1e9|| test>org){
                critical.push_back(edges[i][3]);
            }else{
                int non_test=krushal(edges,n,-1,i);
                if(non_test==org){
                    non_critical.push_back(edges[i][3]);
                }
            }
        }
        vector<vector<int>>ans;
        ans.push_back(critical);
        ans.push_back(non_critical);
        return ans;
    }
};