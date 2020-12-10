class Solution {
public:
    int search(vector<int>& nums, int target) {
        int edge=-1;
        if(nums.size()==1)
        {
            if(target == nums[0])
                return 0;
            else
                return -1;
        }
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i+1])
            {
                edge=i;
                break;
            }
        }
        int r,l;
        if(edge!=-1)
        {
            if(target>nums[edge] || target<nums[edge+1])
                return -1;
            else if(target>=nums[0])
            {
                r=edge;
                l=0;
            }
            else
            {
                r=nums.size()-1;
                l=edge+1;
            }
        }
        else
        {
            if(target>nums[nums.size()-1] || target<nums[0])
                return -1;
            else
            {
                r=nums.size()-1;
                l=0;
            }
        }
        while(r>=l) 
        {
            int k=(r+l)/2;
            if(target==nums[k])
                return k;
            else if(target>nums[k])
                l=k+1;
            else
                r=k-1;
        }
        return -1;
    }
};
