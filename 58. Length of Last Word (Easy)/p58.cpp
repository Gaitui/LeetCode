class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0;
        int k=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                if(k!=0)
                    ans=k;
                k=0;
            }
            else
            {
                k++;
            }
        }
        if(k!=0)
            return k;
        else
            return ans;
    }
};
