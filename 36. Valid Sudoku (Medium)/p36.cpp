class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++)
        {
            int k[10]={0};
            for(int j=0;j<board.size();j++)
            {
                if(board[i][j]!='.')
                {
                    if(k[board[i][j]-'0']==1)
                        return false;
                    else
                        k[board[i][j]-'0']=1;
                }
            }
        }
        for(int i=0;i<board.size();i++)
        {
            int k[10]={0};
            for(int j=0;j<board.size();j++)
            {
                if(board[j][i]!='.')
                {
                    if(k[board[j][i]-'0']==1)
                        return false;
                    else
                        k[board[j][i]-'0']=1;
                }
            }
        }
        for(int i=0;i<board.size();i+=3)
        {
            for(int j=0;j<board.size();j+=3)
            {
                
                int k[10]={0};
                for(int x=0;x<3;x++)
                {
                    for(int z=0;z<3;z++)
                    {
                         if(board[i+x][j+z]!='.')
                        {
                            if(k[board[i+x][j+z]-'0']==1)
                                return false;
                            else
                                k[board[i+x][j+z]-'0']=1;
                        }   
                    }
                }
            }
        }
        return true;
    }
};
