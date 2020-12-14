class Solution {
public:
    bool isMatch(string s, string p){
        bool k[s.size()+1][p.size()+1];
        for(int i=0;i<=s.size();i++)
        {
            for(int j=0;j<=p.size();j++)
            {
                k[i][j]=false;
            }
        }
        k[0][0]=true;
        for(int j=1;j<p.size();j+=2)
        {
            if(p[j]=='*')
            {
                k[0][j]=true;
                k[0][j+1]=true;
            }
            else
            {
                break;
            }
        }
        for(int i=1;i<=s.size();i++)
        {
            for(int j=1;j<=p.size();j++)
            {
                if(p[j-1]=='*')
                {
                    if(p[j-2]==s[i-1] || p[j-2]=='.')
                    {
                        k[i][j-1]=k[i][j-2]+k[i-1][j-1];
                    }
                    else
                    {
                        k[i][j-1]=k[i][j-2];
                    }
                    k[i][j]=k[i][j-1];
                }
                else if(s[i-1]==p[j-1] || p[j-1]=='.')
                {
                    k[i][j]=k[i-1][j-1];
                }
            }
        }
        /*for(int i=0;i<=s.size();i++)
        {
            for(int j=0;j<=p.size();j++)
            {
                cout<<k[i][j]<<" ";
            }
            cout<<endl;
        }*/
        return k[s.size()][p.size()];
    }
};
