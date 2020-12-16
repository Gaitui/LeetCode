class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int left=0;
        int right=nums.size()-1;
        while(right>=left)
        {
            int m=(right+left)/2;
            if(nums[m]>target)
            {
                right=m-1;
            }
            else if(nums[m]<target)
            {
                left=m+1;
            }
            else
            {
                if(m==0 || nums[m]>nums[m-1])
                {
                    ans.push_back(m);
                    right=nums.size()-1;
                    left=m;
                    break;
                }
                else
                {
                    right=m-1;
                }
            }
        }
        if(ans.size()==0)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        while(right>=left)
        {
            int m=(right+left)/2;
            if(nums[m]>target)
            {
                right=m-1;
            }
            else if(nums[m]<target)
            {
                left=m+1;
            }
            else
            {
                if(m==nums.size()-1 || nums[m]<nums[m+1])
                {
                    ans.push_back(m);
                    break;
                }
                else
                {
                    left=m+1;
                }
            }
        }
        return ans;
    }
};
