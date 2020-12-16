class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> row;
        vector<vector<char>> col;
        vector<vector<char>> cub;
        vector<vector<int>> dot;
        vector<char> tmp;
        vector<int> tdot;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board.size();j++)
            {
                if(board[i][j]!='.')
                {
                    tmp.push_back(board[i][j]);
                }
                else
                {
                    tdot.push_back(i);
                    tdot.push_back(j);
                    dot.push_back(tdot);
                    tdot.clear();
                }
            }
            row.push_back(tmp);
            tmp.clear();
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board.size();j++)
            {
                if(board[j][i]!='.')
                {
                    tmp.push_back(board[j][i]);
                }
            }
            col.push_back(tmp);
            tmp.clear();
        }
        for(int i=0;i<board.size();i+=3)
        {
            for(int j=0;j<board.size();j+=3)
            {
                for(int x=0;x<3;x++)
                {
                    for(int z=0;z<3;z++)
                    {
                         if(board[i+x][j+z]!='.')
                        {
                            tmp.push_back(board[i+x][j+z]);
                        }   
                    }
                }
                cub.push_back(tmp);
                tmp.clear();
            }
        }
        bool f=run(board,row,col,cub,dot,0);
        return;
    }
    bool run(vector<vector<char>>& board,vector<vector<char>>& row,vector<vector<char>>& col,vector<vector<char>>& cub,vector<vector<int>> dot,int ndot)
    {
        if(ndot==dot.size())
        {
            return true;
        }
        else
        {
            int x=dot[ndot][0];
            int y=dot[ndot][1];
            int k[10]={0};
            for(int i=0;i<row[x].size();i++)
            {
                k[row[x][i]-'0']=1;
               
            }
            for(int i=0;i<col[y].size();i++)
            {
                k[col[y][i]-'0']=1;
            }
            for(int i=0;i<cub[(x/3*3+y/3)].size();i++)
            {
                k[cub[(x/3*3+y/3)][i]-'0']=1;
            }
            for(int i=1;i<=9;i++)
            {
                if(k[i]!=1)
                {
                    board[x][y]=i+'0';
                    row[x].push_back(i+'0');
                    col[y].push_back(i+'0');
                    cub[(x/3*3+y/3)].push_back(i+'0');
                    bool f=run(board,row,col,cub,dot,ndot+1);
                    if(f)
                    {
                        return true;
                    }
                    else
                    {
                        board[x][y]='.';
                        row[x].pop_back();
                        col[y].pop_back();
                        cub[(x/3*3+y/3)].pop_back();
                    }
                }
            }
            return false;
        }
    }
};
