class Solution {
public:
    void run(vector<int> &nums,vector<vector<int>> &ans,vector<int> tmp,int *flag,int k,int lim)
    {
        tmp.push_back(nums[k]);
        flag[k]=0;
        if(lim==nums.size())
        {
            ans.push_back(tmp);
            flag[k]=1;
            return;
        }
        else
        {
            for(int i=0;i<nums.size();i++)
            {
                if(flag[i])
                {
                    run(nums,ans,tmp,flag,i,lim+1);
                }
            }
        }
        flag[k]=1;
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int *flag = new int[nums.size()];
        vector<int> temp;
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++)
        {
            flag[i]=1;
        }
        for(int i=0;i<nums.size();i++)
        {
            run(nums,ans,temp,flag,i,1);
        }
        return ans;
    }
};
