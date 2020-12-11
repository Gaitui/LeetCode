class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int ms=matrix.size();
        for(int i=0;i<ms-1;i++)
        {
            for(int j=i+1;j<ms;j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<ms;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
        return;
    }
};
