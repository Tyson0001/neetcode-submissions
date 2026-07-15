class Solution {
public: 
    int n;
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        n=nums.size();
        int total=accumulate(nums.begin() ,nums.end() ,0);
        if(total%k!=0) return false;
        int target=total/k;
        sort(nums.begin() ,nums.end(),greater<int>());
        if(nums[0] >target) return false;
        unordered_map<int ,int>map;
        for(auto num:nums) map[num]++;
        return dfs(nums,map,k,0, target,0);
    }
    bool dfs(vector<int>&nums ,unordered_map<int,int>&map , int k ,int sum ,int target, int idx){
       if( k==1 ){
         return true;
       }
       if(idx== n || k<1 ) return false;
       for(int i=idx ;i<n;i++){
        if(map[nums[i]]==0) continue; 
        if(sum+nums[i] > target) continue;
        map[nums[i]]--;
        if(sum+nums[i] ==target){
            if(dfs(nums,map,k-1,0,target,0)) return true;
        }
        else if(sum+nums[i] <target){
            if(dfs(nums,map,k,sum+nums[i],target,i+1)) return true;


        }

        map[nums[i]]++; 
        if(sum==0) return false;
       }
       
       return false;

       
    }
};