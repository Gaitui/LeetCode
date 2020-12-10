class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<4)
            return ans;
		sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-3;i++)
        {
            if(i>0)
            {
                if(nums[i]==nums[i-1])
                    continue;
            }
            for(int j=i+1;j<nums.size()-2;j++)
            {
                if(j>i+1)
                {
                    if(nums[j]==nums[j-1])
                        continue;
                }
                int x=j+1;
                int y=nums.size()-1;
                while(x<y)
                {
                    if(nums[i]+nums[j]+nums[x]+nums[y]==target)
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
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
                    else if(nums[i]+nums[j]+nums[x]+nums[y]>target)
                    {
                        y--;
                    }
                    else
                    {
                        x++;
                    }
                }
            }
        }
        return ans;
    }
};
