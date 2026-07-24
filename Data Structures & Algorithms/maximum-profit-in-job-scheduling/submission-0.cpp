class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) { 
        int n=profit.size();
        vector<vector<int>>job(n,vector<int>(3,0));
        for(int i=0;i<n;i++){
            job[i][0]=startTime[i];
            job[i][1]=endTime[i];
            job[i][2]=profit[i];
        }
        sort(job.begin(),job.end(),[](auto &a,auto &b){
            if(a[0]!=b[0]) return a[0]<b[0];
            return a[1]<b[1];
        });
        vector<int>dp(n,-1);
        return solve(job,0,dp);
    }
    int solve(vector<vector<int>>&job ,int idx,vector<int>&dp ){
        if(idx>=job.size()) return 0; 
        if(dp[idx]!=-1) return dp[idx];
        int not_take =solve(job,idx+1,dp);
        int take=job[idx][2];  
        vector<int>temp={job[idx][1],0,0};
        auto it=lower_bound(job.begin(),job.end(),temp)-job.begin();
        take+=solve(job,it,dp);
        /*if(job[idx][0]>=last_end){
            take=job[idx][2]+solve(job,idx+1,job[idx][1]);
        }*/
        return dp[idx]=max(take,not_take);
    }
};