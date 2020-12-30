class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j] == word[0])
                {
                    board[i][j] = '0';
                    if(run(board,word,i,j,1))
                        return true;
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
    bool run(vector<vector<char>>& board,string &word,int x,int y,int i)
    {
        if(i==word.size())
            return true;
        if(x-1>=0 && board[x-1][y]==word[i])
        {
            board[x-1][y] = '0';
            if(run(board,word,x-1,y,i+1))
                return true;
            board[x-1][y] = word[i];
        }
        if(y+1<board[0].size() && board[x][y+1]==word[i])
        {
            board[x][y+1] = '0';
            if(run(board,word,x,y+1,i+1))
                return true;
            board[x][y+1] = word[i];
        }
        if(x+1<board.size() && board[x+1][y]==word[i])
        {
            board[x+1][y] = '0';
            if(run(board,word,x+1,y,i+1))
                return true;
            board[x+1][y] = word[i];
        }
        if(y-1>=0 && board[x][y-1]==word[i])
        {
            board[x][y-1] = '0';
            if(run(board,word,x,y-1,i+1))
                return true;
            board[x][y-1] = word[i];
        }
        return false;
    }
};
