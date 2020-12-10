class Solution {
public:
    bool isMatch(string s, string p) {
        int snow=0;
        int pnow=0;
        int sbegin=-1;
        int pbegin=-1;
        while(snow<s.size() && pnow<p.size())
        {
            if(p[pnow]=='*')
            {
                int i=pnow+1;
                bool noword=true;
                while(i<p.size())
                {
                    if(p[i]!='*')
                    {
                        pbegin=i;
                        pnow=i;
                        noword=false;
                        break;
                    }
                    i++;
                }
                if(noword)
                {
                    return true;
                }
                sbegin=snow;
            }
            else if((s[snow]!=p[pnow] && p[pnow]!='?') || (pnow+1==p.size() && snow+1<s.size()))
            {
                if(sbegin==-1)
                {
                    return false;
                }
                else
                {
                    sbegin++;
                    snow=sbegin;
                    pnow=pbegin;
                }
            }
            else
            {
                snow++;
                pnow++;
            }
        }
        if(snow==s.size())
        {
            for(int i=pnow;i<p.size();i++)
            {
                if(p[i]!='*')
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    
};
