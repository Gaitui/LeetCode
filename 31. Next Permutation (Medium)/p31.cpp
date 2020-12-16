class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                int l=nums[i];
                swap(nums[i],nums[i+1]);
                for(int j=i+1;j<nums.size();j++)
                {
                    if(nums[j]>l && nums[i]>nums[j])
                    {
                        swap(nums[i],nums[j]);
                    }
                }
                sort(nums.begin()+(i+1),nums.end());
                return;
            }
        }
        sort(nums.begin(),nums.end());
        return;
    }
};
