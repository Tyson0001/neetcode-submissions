class Solution {
public:
    string longestPalindrome(string s) {
        vector<int>p=manacher(s);
        int center_idx=0,res_len=0;
        for(int i=0 ;i<p.size() ;i++){
            if(res_len <p[i]){
                center_idx=i;
                res_len=p[i];
            }
        }
        int res_idx=(center_idx-res_len)/2;
        return s.substr(res_idx,res_len);
    }
    vector<int>manacher(string s){
        int m=s.size();
        string ans="#";
        for(int i=0;i<m;i++){
            ans+=s[i];
            ans+='#';
            
        }
        int n=ans.size();
        vector<int>p(n,0); 
        int l=0,r=0;
        for(int i=0;i<n;i++){
            p[i]=(i<r)? min(r-i ,p[l+r-i]):0;
            while(p[i]+i+1 <n && i-p[i]-1>=0 && ans[p[i]+i+1] ==ans[i-p[i]-1]) p[i]++;
            if(i+p[i] >r) r=p[i]+i , l=i-p[i]; 

        }
        return p;
    }
};
