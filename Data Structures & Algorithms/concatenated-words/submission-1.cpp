class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string>ans;   
        unordered_set<string>st(words.begin() ,words.end());
        int n=words.size();
        for(int i=0;i<n;i++){ 
            st.erase(words[i]);  
            vector<int>dp(words[i].size(),-1);
            if(check(words[i],0,st,dp)){
                ans.push_back(words[i]);
            }
            st.insert(words[i]);
        }
        return ans;
    }
    bool check(string word ,int idx ,unordered_set<string>&st,vector<int>&dp){
        if(idx==word.size()) return true;  
        if(dp[idx]!=-1) return dp[idx];
        int n=word.size();
        string str="";
        for(int i=idx;i<n;i++){
            str+=word[i];
            if(st.count(str)==0) continue;
            if(check(word,i+1,st,dp)) return dp[idx]=true;
        }
        return dp[idx]=false;
    }
};