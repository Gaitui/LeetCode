class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return false;
        if(target<nums[0])
        {
            int i=nums.size()-1;
            while(i>=0 && target<=nums[i] && nums[i]<=nums[0])
            {
                if(target==nums[i])
                    return true;
                i--;
            }
            return false;
        }
        else
        {
            int i=0;
            while(i<nums.size() && target>=nums[i] && nums[i]>=nums[0])
            {
                if(target==nums[i])
                    return true;
                i++;
            }
            return false;
        }
    }
};
