class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> k(nums.size()+1,0);
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0 && nums[i]<=nums.size())
            {
                k[nums[i]]++;
            }
        }
        for(int i=1;i<=nums.size();i++)
        {
            if(k[i]==0)
            {
                return i;
            }
        }
        return nums.size()+1;
    }
};
