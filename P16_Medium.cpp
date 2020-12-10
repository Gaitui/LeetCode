class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans=1e9;
        int sub=1e9;
        for(int i=0;i<nums.size()-2;i++)
        {
            if(i>0)
            {
                if(nums[i]==nums[i-1])
                    continue;
            }
            int x=i+1;
            int y=nums.size()-1;
            while(x<y)
            {
                int k=nums[i]+nums[x]+nums[y];
                //cout<<k<<endl;
                if(sub>abs(target-k))
                {
                    sub=abs(target-k);
                    ans=k;
                }
                if(nums[i]+nums[x]+nums[y]==target)
                {
                    return target;
                }
                else if(nums[i]+nums[x]+nums[y]>target)
                {
                    y--;
                }
                else
                {
                    x++;
                }
            }
        }
        return ans;
    }
};
