class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int k=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(k+nums[i]<nums[i])
            {
                k=nums[i];
            }
            else
            {
                k+=nums[i];
            }
            ans=max(ans,k);
        }
        return ans;
    }
};
