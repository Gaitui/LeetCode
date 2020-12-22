class Solution {
public:
    bool canJump(vector<int>& nums) {
        int far=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            far=max(far,i+nums[i]);
            if(i==far)
                return false;
            if(far>=nums.size()-1)
                return true;
        }
        return true;
    }
};
