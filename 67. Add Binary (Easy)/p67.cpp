class Solution {
public:
    string addBinary(string a, string b) {
        int ls,ss;
        string l,s;
        int carry=0;
        if(a.size()>b.size())
        {
            l=a;
            ls=a.size()-1;
            s=b;
            ss=b.size()-1;
        }
        else
        {
            l=b;
            ls=b.size()-1;
            s=a;
            ss=a.size()-1;
        }
        while(ss>=0)
        {
            int k = (l[ls]-'0')+(s[ss]-'0')+carry;
            if(k==3)
            {
                carry=1;
            }
            else if(k==2)
            {
                l[ls]='0';
                carry=1;
            }
            else
            {
                l[ls]=k+'0';
                carry=0;
            }
            ls--;
            ss--;
        }
        if(carry==1)
        {
            for(int i=ls;i>=0;i--)
            {
                if(l[i]=='1')
                {
                    l[i]='0';
                }
                else
                {
                    l[i]='1';
                    return l;
                }
            }
            string ans;
            ans+='1';
            ans+=l;
            return ans;
        }
        return l;
    }
};
