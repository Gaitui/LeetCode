class Solution {
public:
    string longestPalindrome(string s) {
        bool f;
        int smax=0;
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(s.size()-i<=smax)
                break;
            for(int j=s.size()-1;j>i;j--)
            {
                if(s[i]==s[j])
                {
                    f=true;
                    for(int x=i,z=j;x<z;x++,z--)
                    {
                        if(s[x]!=s[z])
                        {
                            f=false;
                            break;
                        }
                    }
                    if(f)
                    {
                        if(smax<j-i+1)
                        {
                            ans=s.substr(i,j-i+1);
                            smax=j-i+1;
                        }
                    }
                }
            }
        }
        if(smax==0)
        {
            return s.substr(0,1);
        }
        return ans;
    }
};
