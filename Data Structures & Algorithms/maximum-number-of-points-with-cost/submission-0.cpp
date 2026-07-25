class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m=points.size();
        int n=points[0].size();
        vector<long long>dp(n,0);
        for(int row=0;row<m;row++){
            for(int i=0;i<n;i++){
                dp[i]+=points[row][i];
            }
            for(int i=1;i<n;i++){
                dp[i]=max(dp[i] ,dp[i-1]-1);
            }
            for(int i=n-2;i>=0;i--){
                dp[i]=max(dp[i],dp[i+1]-1);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};