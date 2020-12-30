class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        run(ans,tmp,nums,0);
        return ans;
    }
    void run(vector<vector<int>> &ans,vector<int> &tmp,vector<int>& nums,int i)
    {
        ans.push_back(tmp);
        for(;i<nums.size();i++)
        {
            tmp.push_back(nums[i]);
            run(ans,tmp,nums,i+1);
            tmp.pop_back();
        }
        return;
    }
};
