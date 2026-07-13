class Solution {
public: 
   int  n; 
   unordered_map<char ,vector<char>>map;
    vector<string> letterCombinations(string digits) {
        vector<string>ans; 
        n=digits.size();
        
        char t='a';
        for(auto c='2';c<='9';c++){
            if(c=='7' || c=='9'){
                for(int i=0;i<4;i++){
                    map[c].push_back(t++);
                }
            }else{
                for(int i=0;i<3;i++){
                    map[c].push_back(t++);
                }
            }
        }
        string temp="";
        if(digits=="") return ans;
        dfs(ans , temp,digits ,0);
        return ans;
    }
    void dfs(vector<string>&ans , string temp ,string& digits,int idx){
        if(idx==n){
            ans.push_back(temp);
            return;
        }
        for(auto &c:map[digits[idx]]){
            dfs(ans,temp+c,digits,idx+1);

        }
    }
};
