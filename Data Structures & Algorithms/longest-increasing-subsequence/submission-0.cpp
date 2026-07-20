class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            auto it =lower_bound(temp.begin() ,temp.end(),nums[i]);
            if(it==temp.end()){
                temp.push_back(nums[i]);
            }else *it=nums[i];
        }
        return temp.size();
    }
};
