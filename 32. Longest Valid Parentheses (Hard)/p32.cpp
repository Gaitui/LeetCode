class Solution {
public:
    int longestValidParentheses(string s) {
        int rf=0;
        int tmp=0;
        int done=0;
        int rans=0;
        int lans=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='\(')
            {
                rf++;
            }
            else
            {
                rf--;
                if(rf>=0)
                {
                    tmp+=2;
                }
            }
            if(rf==0)
            {
                done+=tmp;
                tmp=0;
            }
            else if(rf<0)
            {
                rans=max(rans,done);
                done=0;
                tmp=0;
                rf=0;
            }
        }
        rans=max(rans,done);
        rf=0;
        tmp=0;
        done=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='\)')
            {
                rf++;
            }
            else
            {
                rf--;
                if(rf>=0)
                {
                    tmp+=2;
                }
            }
            if(rf==0)
            {
                done+=tmp;
                tmp=0;
            }
            else if(rf<0)
            {
                lans=max(lans,done);
                done=0;
                tmp=0;
                rf=0;
            }
        }
        lans=max(lans,done);
        return max(lans,rans);
    }
};
