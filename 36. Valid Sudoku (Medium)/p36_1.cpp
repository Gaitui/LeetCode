class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        return run(board,0,0);
    }
    bool run(vector<vector<char>>& board,int x,int y)
    {
        if(y==9)
            return true;
        else
        {
            if(board[x][y]!='.')
            {
                bool f=true;
                for(int i=0;i<9;i++)
                {
                    if(board[i][y]==board[x][y] && i!=x)
                    {
                        return false;
                    }
                }
                for(int j=0;j<9;j++)
                {
                    if(board[x][j]==board[x][y] && j!=y)
                    {
                        return false;
                    }
                }
                for(int i=x/3*3;i<x/3*3+3;i++)
                {
                    for(int j=y/3*3;j<y/3*3+3;j++)
                    {
                        if(board[i][j]==board[x][y] && (j!=y || i!=x))
                        {
                            return false;
                        }
                    }
                }
                
            }
            if(x+1<9)
            {
                return run(board,x+1,y);
            }
            else
            {
                return run(board,0,y+1);
            }
        }
    }
};
