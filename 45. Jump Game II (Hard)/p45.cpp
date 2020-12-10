class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        int step=0;
        int now=0;
        int k=nums[0];
        while(1)
        {
            step++;
            if(k>=nums.size()-1)
                break;
            int tmp=k;
            int next=now;
            for(int i=1;i<=nums[now];i++)
            {
                if(now+i+nums[now+i]>=tmp && now+i>next)
                {
                    tmp=now+i+nums[now+i];
                    next=now+i;
                }
            }
            k=tmp;
            now=next;
        }
        return step;
    }
};
