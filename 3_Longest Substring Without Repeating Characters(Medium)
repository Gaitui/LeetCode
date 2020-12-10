class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        int k=0;
        int l=1;
        int num=0;
        int ssize=s.size();
        for(int i=1;i<ssize;i++)
        {
            for(int j=k;j<i;j++)
            {
                if(s[i]==s[j])
                {
                    num=max(num,l);
                    k=j+1;
                    l=i-j-1;
                    break;
                }
            }
            l++;
        }
        num=max(num,l);
        return num;
    }
};
