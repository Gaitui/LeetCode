class Solution {
public:
    bool isNumber(string s) {
        bool si=true;
        bool ex=true;
        bool dot=true;
        bool nu=false;
        bool bl=true;
        bool nz=false;
        for(int i=0;i<s.size();i++)
        {
            if(bl)
            {
                if(s[i]>='0' && s[i]<='9')
                {
                    nu=true;
                    si=false;
                    nz=true;
                }
                else if(s[i]=='+' || s[i]=='-')
                {
                    if(si)
                    {
                        si=false;
                        nz=true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(s[i]=='.')
                {
                    if(dot)
                    {
                        dot=false;
                        si=false;
                        nz=true;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(s[i]=='e')
                {
                    if(ex && nu)
                    {
                        nu=false;
                        ex=false;
                        si=true;
                        nz=true;
                        dot=false;
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(s[i]==' ')
                {
                    if(nz)
                        bl=false;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(s[i]!=' ')
                    return false;
            }
        }
        return nu;
    }
};
