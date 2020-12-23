class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        vector<int> tmp;
        for(int i=0;i<n;i++)
        {
            ans.push_back(tmp);
        }
        int up=0;
        int left=0;
        int right=n-1;
        int down=n-1;
        int k=1;
        while(1)
        {
            for(int i=left;i<=right;i++)
            {
                ans[up].insert(ans[up].begin()+i,k);
                k++;
            }
            up++;
            if(k>n*n)
            {
                return ans;
            }
            for(int i=up;i<=down;i++)
            {
                ans[i].insert(ans[i].begin()+left,k);
                k++;
            }
            right--;
            if(k>n*n)
            {
                return ans;
            }
            for(int i=right;i>=left;i--)
            {
                ans[down].insert(ans[down].begin()+left,k);
                k++;
            }
            down--;
            if(k>n*n)
            {
                return ans;
            }
            for(int i=down;i>=up;i--)
            {
                ans[i].insert(ans[i].begin()+left,k);
                k++;
            }
            left++;
            if(k>n*n)
            {
                return ans;
            }
        }
    }
};
