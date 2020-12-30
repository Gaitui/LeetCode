class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        vector<vector<int>> ans;
        if(k>n)
            return ans;
        run(ans,tmp,n,k,1);
        return ans;
    }
    void run(vector<vector<int>>& ans,vector<int>& tmp,int n,int k,int i)
    {
        if(k==0)
        {
            ans.push_back(tmp);
            return;
        }
        else
        {
            for(;i<=n-k+1;i++)
            {
                tmp.push_back(i);
                run(ans,tmp,n,k-1,i+1);
                tmp.pop_back();
            }
            return;
        }
    }
};
