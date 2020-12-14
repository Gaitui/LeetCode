class Solution {
public:
    bool run(string s,string p,int sn,int pn)
    {
        while(sn>=0 && pn>=0)
        {
            if(p[pn]=='*')
            {
                if(p[pn-1]=='.')
                {
                    pn-=2;
                    bool nstar=true;
                    for(;pn>=0;pn--)
                    {
                        if(nstar && p[pn]!='*')
                            break;
                        else
                            nstar=!nstar;
                    }
                    if(pn<0)
                        return true;
                    else
                    {
                        bool find=false;
                        for(;sn>=0;sn--)
                        {
                            if(s[sn]==p[pn] || p[pn]=='.')
                            {
                                find=run(s,p,sn,pn);
                                if(find)
                                    break;
                            }
                        }
                        return find;
                    }
                }
                else
                {
                    pn--;
                    char nrword = p[pn];
                    pn--;
                    if(s[sn]==nrword)
                    {
                        bool f=false;
                        for(;sn>=-1;sn--)
                        {
                            f=run(s,p,sn,pn);
                            if(f || sn<0)
                                break;
                            if(s[sn]!=nrword)
                            {
                                if(s[sn]!='*')
                                    break;
                                else
                                    sn--;
                            }

                        }
                        return f;
                    }
                }
            }
            else if(s[sn]!=p[pn] && p[pn]!='.')
            {
                return false;
            }
            else
            {
                sn--;
                pn--;
            }
        }
        if(sn<0 && pn<0)
            return true;
        else if(sn<0)
        {
            bool nstar=true;
            for(;pn>=0;pn--)
            {
                if(nstar && p[pn]!='*')
                {
                    return false;
                }
                else
                {
                    nstar=!nstar;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isMatch(string s, string p) {
        return run(s,p,s.size()-1,p.size()-1);
    }
};
