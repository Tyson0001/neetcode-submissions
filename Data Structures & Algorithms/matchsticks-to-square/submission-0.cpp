class Solution {
public: 
    int n;
    bool makesquare(vector<int>& matchsticks) {
        n=matchsticks.size();
        int total=accumulate(matchsticks.begin() ,matchsticks.end(),0);
        if(total%4!=0) return false;
        int target=total/4;
        sort(matchsticks.begin() ,matchsticks.end() ,greater()); 
        vector<int>side(4,0);
        return dfs(matchsticks ,0,side,target);
    }
    bool dfs(vector<int>&matchsticks , int idx , vector<int>side , int target){
        if(idx==n){
            return true;
        }
        for(int i=0;i<4;i++){
            if(side[i]+matchsticks[idx] > target) continue;
            bool a=false;
            for(int j=0;j<i;j++){
                if(side[i]==side[j]){
                    a=true;
                    break;
                }
            }
            if(a) continue; 
            side[i]+=matchsticks[idx];
            if(dfs(matchsticks,idx+1,side,target)) return true;
            side[i]-=matchsticks[idx];

        }
        return false;
    }
};