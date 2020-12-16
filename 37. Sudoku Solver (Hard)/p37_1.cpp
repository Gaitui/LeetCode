class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        run(board,0,0);
        return;
    }
    bool run(vector<vector<char>>& board,int x,int y)
    {
        if(y==9)
            return true;
        else
        {
            if(board[x][y]!='.')
            {
                if(x+1<9)
                {
                    return run(board,x+1,y);
                }
                else
                {
                    return run(board,0,y+1);
                }
            }
            else
            {
                for(int k=1;k<=9;k++)
                {
                    bool f=true;
                    for(int i=0;i<9;i++)
                    {
                        if(board[i][y]==k+'0')
                        {
                            f=false;
                            break;
                        }
                    }
                    if(!f)
                        continue;
                    for(int j=0;j<9;j++)
                    {
                        if(board[x][j]==k+'0')
                        {
                            f=false;
                            break;
                        }
                    }
                    if(!f)
                        continue;
                    for(int i=x/3*3;i<x/3*3+3;i++)
                    {
                        for(int j=y/3*3;j<y/3*3+3;j++)
                        {
                            if(board[i][j]==k+'0')
                            {
                                f=false;
                                break;
                            }
                        }
                    }
                    if(f)
                    {
                        board[x][y]=k+'0';
                        if(run(board,x,y))
                        {
                            return true;
                        }
                        else
                        {
                            board[x][y]='.';
                        }
                    }
                }
            }
            return false;
        }
    }
};
