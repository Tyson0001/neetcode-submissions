class DS{
public: 
    vector<int>parent;
    vector<int>rank;
    DS(int n){
        parent.resize(n,0);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int u){
        if(u==parent[u]) return u;
        return parent[u]=find(parent[u]);
    }
    void joint(int u ,int  v){
        int pu=find(u),pv=find(v);
        if(pu==pv) return;
        if(rank[pu]<rank[pv]) parent[pu]=pv;
        else if(rank[pv]<rank[pu]) parent[pv]=pu;
        else parent[pv]=pu,rank[pu]++;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<int,string>email;
        unordered_map<string,int>map;
        int n=accounts.size();
        DS ds(n);
        for(int i=0;i<n;i++){
            string name=accounts[i][0];
            for(int j=1;j<accounts[i].size();j++){
                if(map.find(accounts[i][j]) ==map.end()){
                    map[accounts[i][j]]=i;
                }else{
                    ds.joint(map[accounts[i][j]],i);
                }
            }
            email[i]=name;
        }
        unordered_map<int,set<string>>ans;
        for(int i=0;i<n;i++){
            if(ds.find(i)==i){
                for(int j=1;j<accounts[i].size();j++){
                    ans[i].insert(accounts[i][j]);
                }
            }else{
                for(int j=1;j<accounts[i].size();j++){
                    ans[ds.find(i)].insert(accounts[i][j]);
                }
            }
        }
        vector<vector<string>>res;
        for(auto [num,s]:ans){
            vector<string>temp;
            temp.push_back(email[num]);
            for(auto it:s){
                temp.push_back(it);
            }
            res.push_back(temp);
        }
        return res;

        
    }
};