class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        for(int i=1;i<nums.size();)
        {
            if(nums[i]==nums[i-1])
            {
                count++;
            }
            else
            {
                count=1;
            }
            if(count>2)
            {
                nums.erase(nums.begin()+i);
            }
            else
            {
                i++;
            }
        }
        return nums.size();
    }
};
