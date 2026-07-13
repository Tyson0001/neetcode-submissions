class Solution {
public: 
    int n;
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        string temp="";
        n=s.size();
        dfs(ans,temp,s,0,4);
        return ans;
    }
    void dfs(vector<string>&ans , string temp ,string & s , int idx , int cnt){
        if(idx==n && cnt==0){
            temp.pop_back();
            if((int)temp.size() == n+3)ans.push_back(temp);
            return;
            
        }
        if(cnt<0) return ;
        string str="";
        for(int i=idx ;i<min(idx+3,n);i++){
            if(str!="0") str+=s[i];
            else str=s[i];
            if((stoi(str)-stoi("0")) >=0 &&  (stoi(str)-stoi("0")) <=255){
                dfs(ans, temp+str+'.',s,i+1,cnt-1);
            }
        }
    }
};