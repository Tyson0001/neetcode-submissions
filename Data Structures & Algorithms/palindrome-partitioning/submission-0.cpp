class Solution {
public: 
    int n;
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans; 
        n=s.size();
        vector<string>temp;
        dfs(ans,temp,0,s);
        return ans;
    }
    void dfs(vector<vector<string>>&ans , vector<string>temp ,int idx,string s){
        if(idx==n){
            ans.push_back(temp);
            return ;
        }
        string str="";
        for(int i=idx;i<n;i++){
            str+=s[i];
            if(check(str)){
                temp.push_back(str);
                dfs(ans,temp,i+1,s);
                temp.pop_back();
            }
        }
    }
    bool check(string str){
        int start=0,end=(int)str.size()-1;
        while(start<=end){
            if(str[start++]!=str[end--]) return false;
        }
        return true;
    }
};
