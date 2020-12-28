class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool cz[matrix[0].size()];
        bool rz;
        for(int i=0;i<matrix[0].size();i++)
        {
            cz[i]=false;
        }
        for(int i=0;i<matrix.size();i++)
        {
            rz=false;
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    cz[j]=true;
                    if(!rz)
                    {
                        for(int k=0;k<j;k++)
                        {
                            matrix[i][k]=0;
                        }
                        rz=true;
                    }
                    
                }
                else
                {
                    if(rz)
                    {
                        matrix[i][j]=0;
                    }
                }
            }
        }
        for(int j=0;j<matrix[0].size();j++)
        {
            if(cz[j])
            {
                for(int i=0;i<matrix.size();i++)
                {
                    matrix[i][j]=0;
                }
            }
        }
        return;
    }
};
