class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(); 
        if(n==1) return {nums[0]};
        vector<int>dp(n,1); 
        int last_idx=0, max_len=1;
        vector<int>hash(n,0);
        for(int i=0;i<n;i++) hash[i]=i;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1 >dp[i]){
                    dp[i]=dp[j]+1;
                    
                    hash[i]=j;

                }

            }
            if(max_len<dp[i]){
                max_len=dp[i];
                last_idx=i;
            } 
        }
        vector<int>ans;
        while( last_idx!=hash[last_idx]){
            ans.push_back(nums[last_idx]);
            last_idx=hash[last_idx];
        }
        ans.push_back(nums[last_idx]);
        return ans;
        
    }
};