class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=0;
        if(matrix.size()>1)
        {
            row = findrow(matrix,target);
        }
        if(row==-1)
            return false;
        return findcol(matrix,row,target);
        
    }
    int findrow(vector<vector<int>>& matrix,int t)
    {
        int l=0;
        int r=matrix.size()-1;
        while(r>=l)
        {
            int m=(l+r)/2;
            if(matrix[m][0]<=t)
            {
                if(m==matrix.size()-1 || matrix[m+1][0]>t)
                    return m;
                else
                {
                    l=m+1;
                }
            }
            else
            {
                r=m-1;
            }
        }
        return -1;
    }
    bool findcol(vector<vector<int>>& matrix,int c,int t)
    {
        int l=0;
        int r=matrix[0].size()-1;
        while(r>=l)
        {
            int m=(l+r)/2;
            if(matrix[c][m]==t)
            {
                return true;
            }
            else if(matrix[c][m]<t)
            {
                l=m+1;
            }
            else
            {
                r=m-1;
            }
        }
        return false;
    }
};
