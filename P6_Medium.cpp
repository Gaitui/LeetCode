class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows>=s.size())
        {
            return s;
        }
        string str[numRows];
        int k=0;
        bool dir=true;
        string ans;
        for(int i=0;i<s.size();i++)
        {
            str[k]+=s[i];
            if(dir)
            {
                if(k<numRows-1)
                {
                    k++;
                }
                else
                {
                    dir=false;
                    k--;
                }
            }
            else
            {
                if(k>0)
                {
                    k--;
                }
                else
                {
                    dir=true;
                    k++;
                }
            }
        }
        for(int i=0;i<numRows;i++)
        {
            ans+=str[i];
        }
        return ans;
    }
};
