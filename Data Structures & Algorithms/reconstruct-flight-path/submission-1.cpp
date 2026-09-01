class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>>adj;
        for(auto e:tickets){
            adj[e[0]].push_back(e[1]);
        }
        for(auto & [from,to]:adj){
            sort(to.begin(),to.end(),greater());
        }
        vector<string>ans;
        dfs("JFK",adj,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
    void dfs(string node ,unordered_map<string,vector<string>>&adj,vector<string>&ans){
        while(!adj[node].empty()){
           string temp=adj[node].back();
           adj[node].pop_back();
           dfs(temp,adj,ans);
           
        }
        ans.push_back(node);
    }
};
