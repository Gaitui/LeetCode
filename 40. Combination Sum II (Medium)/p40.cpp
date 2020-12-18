class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> vn;
        vector<vector<int>> ans;
        run(ans,candidates,vn,target,0);
        return ans;
    }
    void run(vector<vector<int>>& ans,vector<int>& c,vector<int>& vn,int target,int k)
    {
        if(target == 0)
        {
            ans.push_back(vn);
            return;
        }
        else
        {
            for(int i=k;i<c.size();i++)
            {
                if(i==k || c[i]!=c[i-1])
                {
                    if(target-c[i]>=0)
                    {
                        vn.push_back(c[i]);
                        run(ans,c,vn,target-c[i],i+1);
                        vn.pop_back();
                    }
                    else
                    {
                        break;
                    }
                }
            }
            return;
        }
    }
};
