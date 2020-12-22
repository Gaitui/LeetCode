class Solution {
public:
    int totalNQueens(int n) {
        string stmp;
        vector<string> vstmp;
        int ans=0;
        for(int i=0;i<n;i++)
            stmp+='.';
        for(int i=0;i<n;i++)
            vstmp.push_back(stmp);
        run(ans,vstmp,n,0);
        return ans;
    }
    void run(int& ans,vector<string>& chizu,int n,int k)
    {
        if(k==n)
        {
            ans++;
        }
        else
        {
            for(int i=0;i<chizu.size();i++)
            {
                bool f=true;
                for(int j=0;j<chizu.size();j++)
                {
                    if(chizu[i][j]=='Q')
                    {
                        f=false;
                        break;
                    }
                    if(i-j>=0 && k-j>=0 && chizu[i-j][k-j]=='Q')
                    {
                        f=false;
                        break;
                    }
                    if(i+j<chizu.size() && k-j>=0 && chizu[i+j][k-j]=='Q')
                    {
                        f=false;
                        break;
                    }
                }
                if(f)
                {
                    chizu[i][k]='Q';
                    run(ans,chizu,n,k+1);
                    chizu[i][k]='.';
                }
            }
            return;
        }
    }
};
