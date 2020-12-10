class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int minus=-1;
		int zero=-1;
		int plus=-1;
        if(nums.size()<3)
            return ans;
		sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2 && nums[i]<=0;i++)
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
                if(nums[i]+nums[x]+nums[y]==0)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[x]);
                    temp.push_back(nums[y]);
                    ans.push_back(temp);
                    while(x<y)
                    {
                        x++;
                        if(nums[x]!=nums[x-1])
                            break;
                    }
                }
                else if(nums[i]+nums[x]+nums[y]>0)
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
