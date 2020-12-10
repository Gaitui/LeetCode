class Solution {
public:
    int jump(vector<int>& nums) {
        int step=0;
        int far=0;
        int Maxfar=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            far=max(far,i+nums[i]);
            if(i==Maxfar)
            {
                step++;
                Maxfar=far;
            }
        }
        return step;
    }
};
