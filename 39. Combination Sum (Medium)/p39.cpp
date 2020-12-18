class Solution {
public:
    void run(vector<vector<int>>& ans,vector<int>& c,vector<int>& vn,int tar,int now)
    {
        if(tar==0)
        {
            ans.push_back(vn);
            return;
        }
        else
        {
            for(int i=now;i<c.size();i++)
            {
                if(tar-c[i]>=0)
                {
                    vn.push_back(c[i]);
                    run(ans,c,vn,tar-c[i],i);
                    vn.pop_back();
                }
            }
            return;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> vn;
        run(ans,candidates,vn,target,0);
        return ans;
    }
};
