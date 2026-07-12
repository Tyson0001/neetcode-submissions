class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        long long n=nums.size();
        long long num=(1<<n); 
        vector<vector<int>>ans;
        for(long long i=0;i<num;i++){
            vector<int>temp;
            for(long long j=0;j<n;j++){
                if(i&(1<<j)) temp.push_back(nums[j]);

            }
            ans.push_back(temp);

        }
        return ans;
    }
};
