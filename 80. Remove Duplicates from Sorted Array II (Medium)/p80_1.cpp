class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int i=1;
        int j=1;
        for(;i<nums.size();)
        {
            if(nums[i]==nums[i-1])
            {
                count++;
            }
            else
            {
                count=1;
            }
            if(count<=2)
            {
                nums[j]=nums[i];
                j++;
            }
            i++;
        }
        return j;
    }
};
