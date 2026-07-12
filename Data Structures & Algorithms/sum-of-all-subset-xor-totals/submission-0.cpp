class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        long long n=nums.size();
        long long num=(1<<n); 
        int ans=0;
        for(long long i=0;i<(num);i++){  
            int xorr=0;
            for(long long j=0;j<n;j++){
                if(i&(1<<j))xorr=xorr^nums[j];

            }
            ans+=xorr;
        }
        return ans;
    }
};