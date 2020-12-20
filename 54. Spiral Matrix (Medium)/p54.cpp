class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int up=0;
        int left=0;
        int right=matrix[0].size()-1;
        int down=matrix.size()-1;
        vector<int> ans;
        while(1)
        {
            //cout<<"up="<<up<<" right="<<right<<" down="<<down<<" left="<<left<<endl;
            for(int i=left;i<=right;i++)
            {
                ans.push_back(matrix[up][i]);
            }
            up++;
            if(up>down)
            {
                return ans;
            }
            for(int i=up;i<=down;i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(left>right)
            {
                return ans;
            }
            for(int i=right;i>=left;i--)
            {
                ans.push_back(matrix[down][i]);
            }
            down--;
            if(up>down)
            {
                return ans;
            }
            for(int i=down;i>=up;i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
            if(left>right)
            {
                return ans;
            }
        }
    }
};
