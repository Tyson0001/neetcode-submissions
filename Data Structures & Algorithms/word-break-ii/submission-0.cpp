class Solution {
public: 
    int n;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>ans;
        n=s.size();
        unordered_set<string>st(wordDict.begin() ,wordDict.end());
        dfs(ans,st,0,"",s);
        return ans;

    }
    void dfs(vector<string>&ans , unordered_set<string>&st,int idx,string temp,string &s){
        if(idx==n){
            temp.pop_back();
            ans.push_back(temp);
            return ;
        } 
        string str="";
        string org=temp;
        for(int i=idx;i<n;i++){
            str+=s[i];
            if(st.count(str)==0) continue;
            temp+=str+" ";
            dfs(ans,st,i+1,temp,s);
            temp=org;
            
            
        }
    }
};