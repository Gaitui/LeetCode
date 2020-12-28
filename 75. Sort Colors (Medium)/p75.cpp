class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c[3];
        for(int i=0;i<3;i++)
            c[i]=0;
        for(int i=0;i<nums.size();i++)
        {
            c[nums[i]]++;
        }
        int k=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<c[i];j++,k++)
            {
                nums[k]=i;
            }
        }
        return;
    }
};
